#!/bin/bash
curdir=$(pwd)
workspaceFolder="/Users/tonyvarghese/Study/Compilers/LearnAdvancedCompilers"
LLVM_DIR=/Volumes/SamsungT5/Apps/llvm-project/build

cd $workspaceFolder
directory_name="build"
if [ ! -d "$directory_name" ]; then
    # If it doesn't exist, create it
    mkdir "$directory_name"
fi
cd $directory_name

cmake -DCMAKE_BUILD_TYPE=Debug -DLT_LLVM_INSTALL_DIR=$LLVM_DIR ..
# LLVM_DIR=/Volumes/SamsungT5/Apps/llvm-project/build/lib/cmake/llvm cmake ..

make
cd $curdir