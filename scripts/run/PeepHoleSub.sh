#!/bin/bash
curdir=$(pwd)
LLVM_DIR=/Volumes/SamsungT5/Apps/llvm-project/build
workspaceFolder="/Users/tonyvarghese/Study/Compilers/LearnAdvancedCompilers"
cd $workspaceFolder/inputs
# Generate an LLVM file to analyze
clang -emit-llvm -S input_sub.c -o input_sub.ll
# Run the pass through opt
$LLVM_DIR/bin/opt -load-pass-plugin $workspaceFolder/build/lib/libPeepHoleSub.dylib --passes="PeepHoleSub" -S input_sub.ll -o out_sub.ll -debug
cd $curdir