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
include any/CMakeFiles/test_any.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include any/CMakeFiles/test_any.dir/compiler_depend.make

# Include the progress variables for this target.
include any/CMakeFiles/test_any.dir/progress.make

# Include the compile flags for this target's objects.
include any/CMakeFiles/test_any.dir/flags.make

any/CMakeFiles/test_any.dir/test.cpp.o: any/CMakeFiles/test_any.dir/flags.make
any/CMakeFiles/test_any.dir/test.cpp.o: /home/julive/julive/any/test.cpp
any/CMakeFiles/test_any.dir/test.cpp.o: any/CMakeFiles/test_any.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object any/CMakeFiles/test_any.dir/test.cpp.o"
	cd /home/julive/julive/build/any && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT any/CMakeFiles/test_any.dir/test.cpp.o -MF CMakeFiles/test_any.dir/test.cpp.o.d -o CMakeFiles/test_any.dir/test.cpp.o -c /home/julive/julive/any/test.cpp

any/CMakeFiles/test_any.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_any.dir/test.cpp.i"
	cd /home/julive/julive/build/any && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/any/test.cpp > CMakeFiles/test_any.dir/test.cpp.i

any/CMakeFiles/test_any.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_any.dir/test.cpp.s"
	cd /home/julive/julive/build/any && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/any/test.cpp -o CMakeFiles/test_any.dir/test.cpp.s

# Object files for target test_any
test_any_OBJECTS = \
"CMakeFiles/test_any.dir/test.cpp.o"

# External object files for target test_any
test_any_EXTERNAL_OBJECTS =

test_any: any/CMakeFiles/test_any.dir/test.cpp.o
test_any: any/CMakeFiles/test_any.dir/build.make
test_any: _deps/catch2-build/src/libCatch2Maind.a
test_any: _deps/catch2-build/src/libCatch2d.a
test_any: any/CMakeFiles/test_any.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../test_any"
	cd /home/julive/julive/build/any && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_any.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
any/CMakeFiles/test_any.dir/build: test_any
.PHONY : any/CMakeFiles/test_any.dir/build

any/CMakeFiles/test_any.dir/clean:
	cd /home/julive/julive/build/any && $(CMAKE_COMMAND) -P CMakeFiles/test_any.dir/cmake_clean.cmake
.PHONY : any/CMakeFiles/test_any.dir/clean

any/CMakeFiles/test_any.dir/depend:
	cd /home/julive/julive/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julive/julive /home/julive/julive/any /home/julive/julive/build /home/julive/julive/build/any /home/julive/julive/build/any/CMakeFiles/test_any.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : any/CMakeFiles/test_any.dir/depend

