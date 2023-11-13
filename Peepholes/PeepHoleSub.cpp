//==============================================================================
// FILE:
//    Peepholes/PeepHoleSub.cpp
//
// DESCRIPTION:
//    Obfuscation for integer sub instructions through Mixed Boolean Arithmetic
//    (MBA). This pass performs an instruction substitution based on this
//    equality:
//      a - b == (a + ~b) + 1
//    See formula 2.2 (j) in [1].
//
// USAGE:
//    1. New pass maanger:
//      $ opt -load-pass-plugin
//      <BUILD_DIR>/lib/libReplaceIntSubInstWithCompAdd.{so|dylib} `\`
//        -passes=-"PeepHoleSub" <bitcode-file>
//
//  [1] "Hacker's Delight" by Henry S. Warren, Jr.
//
// License: MIT
//==============================================================================

#include "PeepHoleSub.h"

#define DEBUG_TYPE "peephole-sub"

using namespace llvm;

PreservedAnalyses PeepHoleSub::run(Function& F, FunctionAnalysisManager& FAM) {
  bool changed = false;
  for (auto& BB : F) {
    for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
      // skip if it is not a binary instruction
      auto* binOp = dyn_cast<BinaryOperator>(I);
      if (!binOp) {
        continue;
      }

      // Check for Integer Subtraction instructions
      auto opCode = binOp->getOpcode();
      if (opCode != Instruction::Sub || !binOp->getType()->isIntegerTy()) {
        continue;
      }

      IRBuilder<> builder(binOp);

      // Create Instruction (a + ~b) + 1
      Instruction* nv = BinaryOperator::CreateAdd(
          builder.CreateAdd(binOp->getOperand(0),
                            builder.CreateNot(binOp->getOperand(1))),
          ConstantInt::get(binOp->getType(), 1));

      LLVM_DEBUG(dbgs() << *binOp << " -> " << *nv << "\n");

      ReplaceInstWithInst(&BB, I, nv);
      changed = true;
    }
  }
  return changed ? PreservedAnalyses::none() : PreservedAnalyses::all();
}

// Pass Manager Registration
llvm::PassPluginLibraryInfo getPeepHoleSubPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "PeepHoleSub", LLVM_VERSION_STRING,
          [](PassBuilder& PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager& FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "PeepHoleSub") {
                    FPM.addPass(PeepHoleSub());
                    return true;
                  }
                  return false;
                });
          }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getPeepHoleSubPluginInfo();
}
