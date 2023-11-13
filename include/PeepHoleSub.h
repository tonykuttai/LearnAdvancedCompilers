#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/Constants.h"
#include "llvm/Support/Debug.h"

using namespace llvm;

namespace llvm {
class PeepHoleSub
    : public PassInfoMixin<PeepHoleSub> {
 public:
  PreservedAnalyses run(Function& F, FunctionAnalysisManager& FAM);

  static bool isRequired() { return true; }
};
}  // namespace llvm
