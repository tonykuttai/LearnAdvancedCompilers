cd build
LLVM_DIR=`brew --prefix llvm`/lib/cmake/llvm cmake ..
make
cd ..