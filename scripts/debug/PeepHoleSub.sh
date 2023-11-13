#!/bin/bash
curdir=$(pwd)
LLVM_DIR=/Volumes/SamsungT5/Apps/llvm-project/build
workspaceFolder="/Users/tonyvarghese/Study/Compilers/LearnAdvancedCompilers"
cd $workspaceFolder/inputs

clang -emit-llvm -S input_sub.c -o input_sub.ll
lldb -- $LLVM_DIR/bin/opt -S -load-pass-plugin $workspaceFolder/build/lib/libPeepHoleSub.dylib --passes="PeepHoleSub" input_sub.ll -o out.ll
cd $curdir
