# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chuck/Src/Simple

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chuck/Src/Simple/build

# Utility rule file for format.

# Include any custom commands dependencies for this target.
include CMakeFiles/format.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/format.dir/progress.make

CMakeFiles/format:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/chuck/Src/Simple/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Format the source code"
	clang-format --verbose -i /home/chuck/Src/Simple/src/ast/ast.c /home/chuck/Src/Simple/src/ast/ast.h /home/chuck/Src/Simple/src/common/buffer.c /home/chuck/Src/Simple/src/common/buffer.h /home/chuck/Src/Simple/src/common/cmderrors.c /home/chuck/Src/Simple/src/common/cmderrors.h /home/chuck/Src/Simple/src/common/cmdline.c /home/chuck/Src/Simple/src/common/cmdline.h /home/chuck/Src/Simple/src/common/cmdparse.c /home/chuck/Src/Simple/src/common/cmdparse.h /home/chuck/Src/Simple/src/common/hash.c /home/chuck/Src/Simple/src/common/hash.h /home/chuck/Src/Simple/src/common/memory.c /home/chuck/Src/Simple/src/common/memory.h /home/chuck/Src/Simple/src/common/myassert.h /home/chuck/Src/Simple/src/common/ptr_lst.c /home/chuck/Src/Simple/src/common/ptr_lst.h /home/chuck/Src/Simple/src/common/str.c /home/chuck/Src/Simple/src/common/str.h /home/chuck/Src/Simple/src/common/str_lst.c /home/chuck/Src/Simple/src/common/str_lst.h /home/chuck/Src/Simple/src/parse/parse.c /home/chuck/Src/Simple/src/scanner/scan.h /home/chuck/Src/Simple/src/simple/main.c

format: CMakeFiles/format
format: CMakeFiles/format.dir/build.make
.PHONY : format

# Rule to build all files generated by this target.
CMakeFiles/format.dir/build: format
.PHONY : CMakeFiles/format.dir/build

CMakeFiles/format.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/format.dir/cmake_clean.cmake
.PHONY : CMakeFiles/format.dir/clean

CMakeFiles/format.dir/depend:
	cd /home/chuck/Src/Simple/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuck/Src/Simple /home/chuck/Src/Simple /home/chuck/Src/Simple/build /home/chuck/Src/Simple/build /home/chuck/Src/Simple/build/CMakeFiles/format.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/format.dir/depend

