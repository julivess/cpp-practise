# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/julive/julive

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julive/julive/build

# Include any dependencies generated for this target.
include local-max/CMakeFiles/test_local_max.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include local-max/CMakeFiles/test_local_max.dir/compiler_depend.make

# Include the progress variables for this target.
include local-max/CMakeFiles/test_local_max.dir/progress.make

# Include the compile flags for this target's objects.
include local-max/CMakeFiles/test_local_max.dir/flags.make

local-max/CMakeFiles/test_local_max.dir/test.cpp.o: local-max/CMakeFiles/test_local_max.dir/flags.make
local-max/CMakeFiles/test_local_max.dir/test.cpp.o: /home/julive/julive/local-max/test.cpp
local-max/CMakeFiles/test_local_max.dir/test.cpp.o: local-max/CMakeFiles/test_local_max.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object local-max/CMakeFiles/test_local_max.dir/test.cpp.o"
	cd /home/julive/julive/build/local-max && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT local-max/CMakeFiles/test_local_max.dir/test.cpp.o -MF CMakeFiles/test_local_max.dir/test.cpp.o.d -o CMakeFiles/test_local_max.dir/test.cpp.o -c /home/julive/julive/local-max/test.cpp

local-max/CMakeFiles/test_local_max.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_local_max.dir/test.cpp.i"
	cd /home/julive/julive/build/local-max && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/local-max/test.cpp > CMakeFiles/test_local_max.dir/test.cpp.i

local-max/CMakeFiles/test_local_max.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_local_max.dir/test.cpp.s"
	cd /home/julive/julive/build/local-max && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/local-max/test.cpp -o CMakeFiles/test_local_max.dir/test.cpp.s

# Object files for target test_local_max
test_local_max_OBJECTS = \
"CMakeFiles/test_local_max.dir/test.cpp.o"

# External object files for target test_local_max
test_local_max_EXTERNAL_OBJECTS =

test_local_max: local-max/CMakeFiles/test_local_max.dir/test.cpp.o
test_local_max: local-max/CMakeFiles/test_local_max.dir/build.make
test_local_max: _deps/catch2-build/src/libCatch2Maind.a
test_local_max: _deps/catch2-build/src/libCatch2d.a
test_local_max: local-max/CMakeFiles/test_local_max.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../test_local_max"
	cd /home/julive/julive/build/local-max && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_local_max.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
local-max/CMakeFiles/test_local_max.dir/build: test_local_max
.PHONY : local-max/CMakeFiles/test_local_max.dir/build

local-max/CMakeFiles/test_local_max.dir/clean:
	cd /home/julive/julive/build/local-max && $(CMAKE_COMMAND) -P CMakeFiles/test_local_max.dir/cmake_clean.cmake
.PHONY : local-max/CMakeFiles/test_local_max.dir/clean

local-max/CMakeFiles/test_local_max.dir/depend:
	cd /home/julive/julive/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julive/julive /home/julive/julive/local-max /home/julive/julive/build /home/julive/julive/build/local-max /home/julive/julive/build/local-max/CMakeFiles/test_local_max.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : local-max/CMakeFiles/test_local_max.dir/depend
