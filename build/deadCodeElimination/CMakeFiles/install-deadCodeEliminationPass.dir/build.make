# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations/build

# Utility rule file for install-deadCodeEliminationPass.

# Include any custom commands dependencies for this target.
include deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass.dir/compiler_depend.make

# Include the progress variables for this target.
include deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass.dir/progress.make

deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass:
	cd /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations/build/deadCodeElimination && /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -DCMAKE_INSTALL_COMPONENT="deadCodeEliminationPass" -P /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations/build/cmake_install.cmake

install-deadCodeEliminationPass: deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass
install-deadCodeEliminationPass: deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass.dir/build.make
.PHONY : install-deadCodeEliminationPass

# Rule to build all files generated by this target.
deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass.dir/build: install-deadCodeEliminationPass
.PHONY : deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass.dir/build

deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass.dir/clean:
	cd /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations/build/deadCodeElimination && $(CMAKE_COMMAND) -P CMakeFiles/install-deadCodeEliminationPass.dir/cmake_clean.cmake
.PHONY : deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass.dir/clean

deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass.dir/depend:
	cd /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations/deadCodeElimination /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations/build /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations/build/deadCodeElimination /Users/tonyvarghese/Study/Compilers/cs6120/llvm/optimizations/build/deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : deadCodeElimination/CMakeFiles/install-deadCodeEliminationPass.dir/depend

