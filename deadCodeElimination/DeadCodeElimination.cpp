#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace llvm {
class DeadCodeEliminationPass : public PassInfoMixin<DeadCodeEliminationPass> {
 public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM) {
    SmallPtrSet<Value *, 16> LiveValues;

    for (BasicBlock &BB : F) {
      for (Instruction &I : BB) {
        if (isa<StoreInst>(&I)) {
          // If this instruction stores a value into a variable, add the
          // variable to LiveValues.
          LiveValues.insert(I.getOperand(1));
        } else if (isa<LoadInst>(&I)) {
          // If this instruction loads a value from a variable, add the variable
          // to LiveValues.
          LiveValues.insert(&I);
        }
      }
    }

    // Iterate through the instructions and remove dead code.
    bool Modified = false;
    for (BasicBlock &BB : F) {
      for (auto I = BB.begin(); I != BB.end();) {
        Instruction &Inst = *I;
        if (!LiveValues.count(&Inst)) {
          // This instruction is dead; remove it.
          I = Inst.eraseFromParent();
          Modified = true;
        } else {
          ++I;
        }
      }
    }

    return Modified ? PreservedAnalyses::none() : PreservedAnalyses::all();
  }
};

}  // namespace llvm

