# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Exercise_W5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exercise_W5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exercise_W5.dir/flags.make

CMakeFiles/Exercise_W5.dir/main.cpp.o: CMakeFiles/Exercise_W5.dir/flags.make
CMakeFiles/Exercise_W5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Exercise_W5.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Exercise_W5.dir/main.cpp.o -c /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5/main.cpp

CMakeFiles/Exercise_W5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exercise_W5.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5/main.cpp > CMakeFiles/Exercise_W5.dir/main.cpp.i

CMakeFiles/Exercise_W5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exercise_W5.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5/main.cpp -o CMakeFiles/Exercise_W5.dir/main.cpp.s

# Object files for target Exercise_W5
Exercise_W5_OBJECTS = \
"CMakeFiles/Exercise_W5.dir/main.cpp.o"

# External object files for target Exercise_W5
Exercise_W5_EXTERNAL_OBJECTS =

Exercise_W5: CMakeFiles/Exercise_W5.dir/main.cpp.o
Exercise_W5: CMakeFiles/Exercise_W5.dir/build.make
Exercise_W5: CMakeFiles/Exercise_W5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Exercise_W5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Exercise_W5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exercise_W5.dir/build: Exercise_W5

.PHONY : CMakeFiles/Exercise_W5.dir/build

CMakeFiles/Exercise_W5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Exercise_W5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Exercise_W5.dir/clean

CMakeFiles/Exercise_W5.dir/depend:
	cd /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5 /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5 /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5/cmake-build-debug /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5/cmake-build-debug /Users/hongfeizhang/Programming/ENGI-3894/Exercise-W5/cmake-build-debug/CMakeFiles/Exercise_W5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Exercise_W5.dir/depend

