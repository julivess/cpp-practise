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
include dungeon/CMakeFiles/test_dungeon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dungeon/CMakeFiles/test_dungeon.dir/compiler_depend.make

# Include the progress variables for this target.
include dungeon/CMakeFiles/test_dungeon.dir/progress.make

# Include the compile flags for this target's objects.
include dungeon/CMakeFiles/test_dungeon.dir/flags.make

dungeon/CMakeFiles/test_dungeon.dir/test.cpp.o: dungeon/CMakeFiles/test_dungeon.dir/flags.make
dungeon/CMakeFiles/test_dungeon.dir/test.cpp.o: /home/julive/julive/dungeon/test.cpp
dungeon/CMakeFiles/test_dungeon.dir/test.cpp.o: dungeon/CMakeFiles/test_dungeon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dungeon/CMakeFiles/test_dungeon.dir/test.cpp.o"
	cd /home/julive/julive/build/dungeon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT dungeon/CMakeFiles/test_dungeon.dir/test.cpp.o -MF CMakeFiles/test_dungeon.dir/test.cpp.o.d -o CMakeFiles/test_dungeon.dir/test.cpp.o -c /home/julive/julive/dungeon/test.cpp

dungeon/CMakeFiles/test_dungeon.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_dungeon.dir/test.cpp.i"
	cd /home/julive/julive/build/dungeon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/dungeon/test.cpp > CMakeFiles/test_dungeon.dir/test.cpp.i

dungeon/CMakeFiles/test_dungeon.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_dungeon.dir/test.cpp.s"
	cd /home/julive/julive/build/dungeon && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/dungeon/test.cpp -o CMakeFiles/test_dungeon.dir/test.cpp.s

# Object files for target test_dungeon
test_dungeon_OBJECTS = \
"CMakeFiles/test_dungeon.dir/test.cpp.o"

# External object files for target test_dungeon
test_dungeon_EXTERNAL_OBJECTS =

test_dungeon: dungeon/CMakeFiles/test_dungeon.dir/test.cpp.o
test_dungeon: dungeon/CMakeFiles/test_dungeon.dir/build.make
test_dungeon: _deps/catch2-build/src/libCatch2Maind.a
test_dungeon: _deps/catch2-build/src/libCatch2d.a
test_dungeon: dungeon/CMakeFiles/test_dungeon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../test_dungeon"
	cd /home/julive/julive/build/dungeon && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_dungeon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dungeon/CMakeFiles/test_dungeon.dir/build: test_dungeon
.PHONY : dungeon/CMakeFiles/test_dungeon.dir/build

dungeon/CMakeFiles/test_dungeon.dir/clean:
	cd /home/julive/julive/build/dungeon && $(CMAKE_COMMAND) -P CMakeFiles/test_dungeon.dir/cmake_clean.cmake
.PHONY : dungeon/CMakeFiles/test_dungeon.dir/clean

dungeon/CMakeFiles/test_dungeon.dir/depend:
	cd /home/julive/julive/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julive/julive /home/julive/julive/dungeon /home/julive/julive/build /home/julive/julive/build/dungeon /home/julive/julive/build/dungeon/CMakeFiles/test_dungeon.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : dungeon/CMakeFiles/test_dungeon.dir/depend
