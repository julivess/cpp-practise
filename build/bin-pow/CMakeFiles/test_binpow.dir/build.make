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
include bin-pow/CMakeFiles/test_binpow.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bin-pow/CMakeFiles/test_binpow.dir/compiler_depend.make

# Include the progress variables for this target.
include bin-pow/CMakeFiles/test_binpow.dir/progress.make

# Include the compile flags for this target's objects.
include bin-pow/CMakeFiles/test_binpow.dir/flags.make

bin-pow/CMakeFiles/test_binpow.dir/test.cpp.o: bin-pow/CMakeFiles/test_binpow.dir/flags.make
bin-pow/CMakeFiles/test_binpow.dir/test.cpp.o: /home/julive/julive/bin-pow/test.cpp
bin-pow/CMakeFiles/test_binpow.dir/test.cpp.o: bin-pow/CMakeFiles/test_binpow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin-pow/CMakeFiles/test_binpow.dir/test.cpp.o"
	cd /home/julive/julive/build/bin-pow && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bin-pow/CMakeFiles/test_binpow.dir/test.cpp.o -MF CMakeFiles/test_binpow.dir/test.cpp.o.d -o CMakeFiles/test_binpow.dir/test.cpp.o -c /home/julive/julive/bin-pow/test.cpp

bin-pow/CMakeFiles/test_binpow.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_binpow.dir/test.cpp.i"
	cd /home/julive/julive/build/bin-pow && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/bin-pow/test.cpp > CMakeFiles/test_binpow.dir/test.cpp.i

bin-pow/CMakeFiles/test_binpow.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_binpow.dir/test.cpp.s"
	cd /home/julive/julive/build/bin-pow && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/bin-pow/test.cpp -o CMakeFiles/test_binpow.dir/test.cpp.s

# Object files for target test_binpow
test_binpow_OBJECTS = \
"CMakeFiles/test_binpow.dir/test.cpp.o"

# External object files for target test_binpow
test_binpow_EXTERNAL_OBJECTS =

test_binpow: bin-pow/CMakeFiles/test_binpow.dir/test.cpp.o
test_binpow: bin-pow/CMakeFiles/test_binpow.dir/build.make
test_binpow: _deps/catch2-build/src/libCatch2Maind.a
test_binpow: _deps/catch2-build/src/libCatch2d.a
test_binpow: bin-pow/CMakeFiles/test_binpow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../test_binpow"
	cd /home/julive/julive/build/bin-pow && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_binpow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin-pow/CMakeFiles/test_binpow.dir/build: test_binpow
.PHONY : bin-pow/CMakeFiles/test_binpow.dir/build

bin-pow/CMakeFiles/test_binpow.dir/clean:
	cd /home/julive/julive/build/bin-pow && $(CMAKE_COMMAND) -P CMakeFiles/test_binpow.dir/cmake_clean.cmake
.PHONY : bin-pow/CMakeFiles/test_binpow.dir/clean

bin-pow/CMakeFiles/test_binpow.dir/depend:
	cd /home/julive/julive/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julive/julive /home/julive/julive/bin-pow /home/julive/julive/build /home/julive/julive/build/bin-pow /home/julive/julive/build/bin-pow/CMakeFiles/test_binpow.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : bin-pow/CMakeFiles/test_binpow.dir/depend
