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
include scheme/CMakeFiles/test_scheme.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include scheme/CMakeFiles/test_scheme.dir/compiler_depend.make

# Include the progress variables for this target.
include scheme/CMakeFiles/test_scheme.dir/progress.make

# Include the compile flags for this target's objects.
include scheme/CMakeFiles/test_scheme.dir/flags.make

scheme/CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.o: scheme/CMakeFiles/test_scheme.dir/flags.make
scheme/CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.o: /home/julive/julive/scheme/tests/test_boolean.cpp
scheme/CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.o: scheme/CMakeFiles/test_scheme.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object scheme/CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.o"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scheme/CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.o -MF CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.o.d -o CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.o -c /home/julive/julive/scheme/tests/test_boolean.cpp

scheme/CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.i"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/scheme/tests/test_boolean.cpp > CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.i

scheme/CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.s"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/scheme/tests/test_boolean.cpp -o CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.s

scheme/CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.o: scheme/CMakeFiles/test_scheme.dir/flags.make
scheme/CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.o: /home/julive/julive/scheme/tests/test_control_flow.cpp
scheme/CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.o: scheme/CMakeFiles/test_scheme.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object scheme/CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.o"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scheme/CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.o -MF CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.o.d -o CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.o -c /home/julive/julive/scheme/tests/test_control_flow.cpp

scheme/CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.i"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/scheme/tests/test_control_flow.cpp > CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.i

scheme/CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.s"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/scheme/tests/test_control_flow.cpp -o CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.s

scheme/CMakeFiles/test_scheme.dir/tests/test_eval.cpp.o: scheme/CMakeFiles/test_scheme.dir/flags.make
scheme/CMakeFiles/test_scheme.dir/tests/test_eval.cpp.o: /home/julive/julive/scheme/tests/test_eval.cpp
scheme/CMakeFiles/test_scheme.dir/tests/test_eval.cpp.o: scheme/CMakeFiles/test_scheme.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object scheme/CMakeFiles/test_scheme.dir/tests/test_eval.cpp.o"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scheme/CMakeFiles/test_scheme.dir/tests/test_eval.cpp.o -MF CMakeFiles/test_scheme.dir/tests/test_eval.cpp.o.d -o CMakeFiles/test_scheme.dir/tests/test_eval.cpp.o -c /home/julive/julive/scheme/tests/test_eval.cpp

scheme/CMakeFiles/test_scheme.dir/tests/test_eval.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_scheme.dir/tests/test_eval.cpp.i"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/scheme/tests/test_eval.cpp > CMakeFiles/test_scheme.dir/tests/test_eval.cpp.i

scheme/CMakeFiles/test_scheme.dir/tests/test_eval.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_scheme.dir/tests/test_eval.cpp.s"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/scheme/tests/test_eval.cpp -o CMakeFiles/test_scheme.dir/tests/test_eval.cpp.s

scheme/CMakeFiles/test_scheme.dir/tests/test_integer.cpp.o: scheme/CMakeFiles/test_scheme.dir/flags.make
scheme/CMakeFiles/test_scheme.dir/tests/test_integer.cpp.o: /home/julive/julive/scheme/tests/test_integer.cpp
scheme/CMakeFiles/test_scheme.dir/tests/test_integer.cpp.o: scheme/CMakeFiles/test_scheme.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object scheme/CMakeFiles/test_scheme.dir/tests/test_integer.cpp.o"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scheme/CMakeFiles/test_scheme.dir/tests/test_integer.cpp.o -MF CMakeFiles/test_scheme.dir/tests/test_integer.cpp.o.d -o CMakeFiles/test_scheme.dir/tests/test_integer.cpp.o -c /home/julive/julive/scheme/tests/test_integer.cpp

scheme/CMakeFiles/test_scheme.dir/tests/test_integer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_scheme.dir/tests/test_integer.cpp.i"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/scheme/tests/test_integer.cpp > CMakeFiles/test_scheme.dir/tests/test_integer.cpp.i

scheme/CMakeFiles/test_scheme.dir/tests/test_integer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_scheme.dir/tests/test_integer.cpp.s"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/scheme/tests/test_integer.cpp -o CMakeFiles/test_scheme.dir/tests/test_integer.cpp.s

scheme/CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.o: scheme/CMakeFiles/test_scheme.dir/flags.make
scheme/CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.o: /home/julive/julive/scheme/tests/test_lambda.cpp
scheme/CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.o: scheme/CMakeFiles/test_scheme.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object scheme/CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.o"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scheme/CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.o -MF CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.o.d -o CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.o -c /home/julive/julive/scheme/tests/test_lambda.cpp

scheme/CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.i"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/scheme/tests/test_lambda.cpp > CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.i

scheme/CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.s"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/scheme/tests/test_lambda.cpp -o CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.s

scheme/CMakeFiles/test_scheme.dir/tests/test_list.cpp.o: scheme/CMakeFiles/test_scheme.dir/flags.make
scheme/CMakeFiles/test_scheme.dir/tests/test_list.cpp.o: /home/julive/julive/scheme/tests/test_list.cpp
scheme/CMakeFiles/test_scheme.dir/tests/test_list.cpp.o: scheme/CMakeFiles/test_scheme.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object scheme/CMakeFiles/test_scheme.dir/tests/test_list.cpp.o"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scheme/CMakeFiles/test_scheme.dir/tests/test_list.cpp.o -MF CMakeFiles/test_scheme.dir/tests/test_list.cpp.o.d -o CMakeFiles/test_scheme.dir/tests/test_list.cpp.o -c /home/julive/julive/scheme/tests/test_list.cpp

scheme/CMakeFiles/test_scheme.dir/tests/test_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_scheme.dir/tests/test_list.cpp.i"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/scheme/tests/test_list.cpp > CMakeFiles/test_scheme.dir/tests/test_list.cpp.i

scheme/CMakeFiles/test_scheme.dir/tests/test_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_scheme.dir/tests/test_list.cpp.s"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/scheme/tests/test_list.cpp -o CMakeFiles/test_scheme.dir/tests/test_list.cpp.s

scheme/CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.o: scheme/CMakeFiles/test_scheme.dir/flags.make
scheme/CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.o: /home/julive/julive/scheme/tests/test_symbol.cpp
scheme/CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.o: scheme/CMakeFiles/test_scheme.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object scheme/CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.o"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scheme/CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.o -MF CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.o.d -o CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.o -c /home/julive/julive/scheme/tests/test_symbol.cpp

scheme/CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.i"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julive/julive/scheme/tests/test_symbol.cpp > CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.i

scheme/CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.s"
	cd /home/julive/julive/build/scheme && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julive/julive/scheme/tests/test_symbol.cpp -o CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.s

# Object files for target test_scheme
test_scheme_OBJECTS = \
"CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.o" \
"CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.o" \
"CMakeFiles/test_scheme.dir/tests/test_eval.cpp.o" \
"CMakeFiles/test_scheme.dir/tests/test_integer.cpp.o" \
"CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.o" \
"CMakeFiles/test_scheme.dir/tests/test_list.cpp.o" \
"CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.o"

# External object files for target test_scheme
test_scheme_EXTERNAL_OBJECTS =

test_scheme: scheme/CMakeFiles/test_scheme.dir/tests/test_boolean.cpp.o
test_scheme: scheme/CMakeFiles/test_scheme.dir/tests/test_control_flow.cpp.o
test_scheme: scheme/CMakeFiles/test_scheme.dir/tests/test_eval.cpp.o
test_scheme: scheme/CMakeFiles/test_scheme.dir/tests/test_integer.cpp.o
test_scheme: scheme/CMakeFiles/test_scheme.dir/tests/test_lambda.cpp.o
test_scheme: scheme/CMakeFiles/test_scheme.dir/tests/test_list.cpp.o
test_scheme: scheme/CMakeFiles/test_scheme.dir/tests/test_symbol.cpp.o
test_scheme: scheme/CMakeFiles/test_scheme.dir/build.make
test_scheme: _deps/catch2-build/src/libCatch2Maind.a
test_scheme: scheme/liblibscheme.a
test_scheme: _deps/catch2-build/src/libCatch2d.a
test_scheme: scheme/CMakeFiles/test_scheme.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/julive/julive/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../test_scheme"
	cd /home/julive/julive/build/scheme && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_scheme.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
scheme/CMakeFiles/test_scheme.dir/build: test_scheme
.PHONY : scheme/CMakeFiles/test_scheme.dir/build

scheme/CMakeFiles/test_scheme.dir/clean:
	cd /home/julive/julive/build/scheme && $(CMAKE_COMMAND) -P CMakeFiles/test_scheme.dir/cmake_clean.cmake
.PHONY : scheme/CMakeFiles/test_scheme.dir/clean

scheme/CMakeFiles/test_scheme.dir/depend:
	cd /home/julive/julive/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julive/julive /home/julive/julive/scheme /home/julive/julive/build /home/julive/julive/build/scheme /home/julive/julive/build/scheme/CMakeFiles/test_scheme.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : scheme/CMakeFiles/test_scheme.dir/depend
