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
include scheme/CMakeFiles/scheme-repl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include scheme/CMakeFiles/scheme-repl.dir/compiler_depend.make

# Include the progress variables for this target.
include scheme/CMakeFiles/scheme-repl.dir/progress.make

# Include the compile flags for this target's objects.
include scheme/CMakeFiles/scheme-repl.dir/flags.make

scheme/CMakeFiles/scheme-repl.dir/repl/main.cpp.o: scheme/CMakeFiles/scheme-repl.dir/flags.make
scheme/CMakeFiles/scheme-repl.dir/repl/main.cpp.o: /home/julive/julive/scheme/repl/main.cpp
scheme/CMakeFiles/scheme-repl.dir/repl/main.cpp.o: scheme/CMakeFiles/scheme-repl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object scheme/CMakeFiles/scheme-repl.dir/repl/main.cpp.o"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scheme/CMakeFiles/scheme-repl.dir/repl/main.cpp.o -MF CMakeFiles/scheme-repl.dir/repl/main.cpp.o.d -o CMakeFiles/scheme-repl.dir/repl/main.cpp.o -c /home/julive/julive/scheme/repl/main.cpp

scheme/CMakeFiles/scheme-repl.dir/repl/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/scheme-repl.dir/repl/main.cpp.i"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/scheme/repl/main.cpp > CMakeFiles/scheme-repl.dir/repl/main.cpp.i

scheme/CMakeFiles/scheme-repl.dir/repl/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/scheme-repl.dir/repl/main.cpp.s"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/scheme/repl/main.cpp -o CMakeFiles/scheme-repl.dir/repl/main.cpp.s

# Object files for target scheme-repl
scheme__repl_OBJECTS = \
"CMakeFiles/scheme-repl.dir/repl/main.cpp.o"

# External object files for target scheme-repl
scheme__repl_EXTERNAL_OBJECTS =

scheme-repl: scheme/CMakeFiles/scheme-repl.dir/repl/main.cpp.o
scheme-repl: scheme/CMakeFiles/scheme-repl.dir/build.make
scheme-repl: scheme/liblibscheme.a
scheme-repl: scheme/CMakeFiles/scheme-repl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../scheme-repl"
	cd /home/julive/julive/build/scheme && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scheme-repl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
scheme/CMakeFiles/scheme-repl.dir/build: scheme-repl
.PHONY : scheme/CMakeFiles/scheme-repl.dir/build

scheme/CMakeFiles/scheme-repl.dir/clean:
	cd /home/julive/julive/build/scheme && $(CMAKE_COMMAND) -P CMakeFiles/scheme-repl.dir/cmake_clean.cmake
.PHONY : scheme/CMakeFiles/scheme-repl.dir/clean

scheme/CMakeFiles/scheme-repl.dir/depend:
	cd /home/julive/julive/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julive/julive /home/julive/julive/scheme /home/julive/julive/build /home/julive/julive/build/scheme /home/julive/julive/build/scheme/CMakeFiles/scheme-repl.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : scheme/CMakeFiles/scheme-repl.dir/depend

