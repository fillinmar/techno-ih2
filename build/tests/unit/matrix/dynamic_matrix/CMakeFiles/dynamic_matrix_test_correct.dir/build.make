# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fillinmar/techno-ih2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fillinmar/techno-ih2/build

# Include any dependencies generated for this target.
include tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/depend.make

# Include the progress variables for this target.
include tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/progress.make

# Include the compile flags for this target's objects.
include tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/flags.make

tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.o: tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/flags.make
tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.o: ../tests/unit/matrix/dynamic_matrix/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fillinmar/techno-ih2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.o"
	cd /home/fillinmar/techno-ih2/build/tests/unit/matrix/dynamic_matrix && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.o -c /home/fillinmar/techno-ih2/tests/unit/matrix/dynamic_matrix/main.cpp

tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.i"
	cd /home/fillinmar/techno-ih2/build/tests/unit/matrix/dynamic_matrix && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fillinmar/techno-ih2/tests/unit/matrix/dynamic_matrix/main.cpp > CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.i

tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.s"
	cd /home/fillinmar/techno-ih2/build/tests/unit/matrix/dynamic_matrix && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fillinmar/techno-ih2/tests/unit/matrix/dynamic_matrix/main.cpp -o CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.s

tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.o: tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/flags.make
tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.o: ../tests/unit/matrix/dynamic_matrix/matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fillinmar/techno-ih2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.o"
	cd /home/fillinmar/techno-ih2/build/tests/unit/matrix/dynamic_matrix && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.o -c /home/fillinmar/techno-ih2/tests/unit/matrix/dynamic_matrix/matrix.cpp

tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.i"
	cd /home/fillinmar/techno-ih2/build/tests/unit/matrix/dynamic_matrix && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fillinmar/techno-ih2/tests/unit/matrix/dynamic_matrix/matrix.cpp > CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.i

tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.s"
	cd /home/fillinmar/techno-ih2/build/tests/unit/matrix/dynamic_matrix && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fillinmar/techno-ih2/tests/unit/matrix/dynamic_matrix/matrix.cpp -o CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.s

# Object files for target dynamic_matrix_test_correct
dynamic_matrix_test_correct_OBJECTS = \
"CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.o" \
"CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.o"

# External object files for target dynamic_matrix_test_correct
dynamic_matrix_test_correct_EXTERNAL_OBJECTS =

tests/unit/matrix/dynamic_matrix/dynamic_matrix_test_correct: tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/main.cpp.o
tests/unit/matrix/dynamic_matrix/dynamic_matrix_test_correct: tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/matrix.cpp.o
tests/unit/matrix/dynamic_matrix/dynamic_matrix_test_correct: tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/build.make
tests/unit/matrix/dynamic_matrix/dynamic_matrix_test_correct: src/dynamic_matrix/libdynamic_matrix.so
tests/unit/matrix/dynamic_matrix/dynamic_matrix_test_correct: lib/libgtest.a
tests/unit/matrix/dynamic_matrix/dynamic_matrix_test_correct: tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fillinmar/techno-ih2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable dynamic_matrix_test_correct"
	cd /home/fillinmar/techno-ih2/build/tests/unit/matrix/dynamic_matrix && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dynamic_matrix_test_correct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/build: tests/unit/matrix/dynamic_matrix/dynamic_matrix_test_correct

.PHONY : tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/build

tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/clean:
	cd /home/fillinmar/techno-ih2/build/tests/unit/matrix/dynamic_matrix && $(CMAKE_COMMAND) -P CMakeFiles/dynamic_matrix_test_correct.dir/cmake_clean.cmake
.PHONY : tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/clean

tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/depend:
	cd /home/fillinmar/techno-ih2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fillinmar/techno-ih2 /home/fillinmar/techno-ih2/tests/unit/matrix/dynamic_matrix /home/fillinmar/techno-ih2/build /home/fillinmar/techno-ih2/build/tests/unit/matrix/dynamic_matrix /home/fillinmar/techno-ih2/build/tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/unit/matrix/dynamic_matrix/CMakeFiles/dynamic_matrix_test_correct.dir/depend

