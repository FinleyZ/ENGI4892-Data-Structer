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
CMAKE_SOURCE_DIR = /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/W11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/W11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/W11.dir/flags.make

CMakeFiles/W11.dir/main.cpp.o: CMakeFiles/W11.dir/flags.make
CMakeFiles/W11.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/W11.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/W11.dir/main.cpp.o -c /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11/main.cpp

CMakeFiles/W11.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/W11.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11/main.cpp > CMakeFiles/W11.dir/main.cpp.i

CMakeFiles/W11.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/W11.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11/main.cpp -o CMakeFiles/W11.dir/main.cpp.s

# Object files for target W11
W11_OBJECTS = \
"CMakeFiles/W11.dir/main.cpp.o"

# External object files for target W11
W11_EXTERNAL_OBJECTS =

W11: CMakeFiles/W11.dir/main.cpp.o
W11: CMakeFiles/W11.dir/build.make
W11: CMakeFiles/W11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable W11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/W11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/W11.dir/build: W11

.PHONY : CMakeFiles/W11.dir/build

CMakeFiles/W11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/W11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/W11.dir/clean

CMakeFiles/W11.dir/depend:
	cd /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11 /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11 /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11/cmake-build-debug /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11/cmake-build-debug /Users/hongfeizhang/Programming/ENGI-3894/Exercise/W11/cmake-build-debug/CMakeFiles/W11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/W11.dir/depend

