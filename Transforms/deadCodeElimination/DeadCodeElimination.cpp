#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"
#include <set>

using namespace llvm;

namespace llvm {
class DeadCodeEliminationPass : public PassInfoMixin<DeadCodeEliminationPass> {
 public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM) {
    bool changed = false;
    std::set<llvm::Value*> LiveValues;
    SmallVector<Instruction *, 8> ToRemove;
    // Load all the live variables to the set
    for (auto &BB : F) {
      for(auto& I : BB ){
        if(isa<StoreInst>(&I)){
          LiveValues.emplace(I.getOperand(1));
        }else if(isa<LoadInst>(&I)){
          LiveValues.emplace(&I);
        }
      }
    }
    // // Iterate through the instructions and remove the dead code
    bool Modified = false;
    for(auto& BB: F){
      for(auto I = BB.begin(); I != BB.end(); ++I){
        Instruction &Inst = *I;
        if(!LiveValues.count(&Inst)){
          // dead instruction. remove it
          // I = Inst.eraseFromParent();
          ToRemove.push_back(&Inst);
          Modified = true;
        }
      }
    }

    for(auto* I : ToRemove){
      I->eraseFromParent();
    }

    return Modified ? PreservedAnalyses::none() : PreservedAnalyses::all();
  }
};

class DeadCodeModulePass : public PassInfoMixin<DeadCodeModulePass> {
 public:
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &MAM) {
    for (Function &F : M) {
      if (!F.isDeclaration()) {
        FunctionAnalysisManager FAM;
        DeadCodeEliminationPass().run(F, FAM);
      }
    }
    return PreservedAnalyses::all();
  }
};

}  // namespace llvm

extern "C" LLVM_ATTRIBUTE_WEAK llvm::PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return {.APIVersion = LLVM_PLUGIN_API_VERSION,
          .PluginName = "deadCodeElimination pass",
          .PluginVersion = "v0.1",
          .RegisterPassBuilderCallbacks = [](PassBuilder& PB) {
            PB.registerPipelineStartEPCallback(
                [](ModulePassManager& MPM, OptimizationLevel Level) {
                  MPM.addPass(DeadCodeModulePass());
                });
          }};
}