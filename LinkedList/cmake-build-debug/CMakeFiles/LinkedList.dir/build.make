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
CMAKE_SOURCE_DIR = /Users/hongfeizhang/Programming/ENGI-3894/LinkedList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hongfeizhang/Programming/ENGI-3894/LinkedList/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LinkedList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LinkedList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkedList.dir/flags.make

CMakeFiles/LinkedList.dir/LinkedList.cpp.o: CMakeFiles/LinkedList.dir/flags.make
CMakeFiles/LinkedList.dir/LinkedList.cpp.o: ../LinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hongfeizhang/Programming/ENGI-3894/LinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LinkedList.dir/LinkedList.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LinkedList.dir/LinkedList.cpp.o -c /Users/hongfeizhang/Programming/ENGI-3894/LinkedList/LinkedList.cpp

CMakeFiles/LinkedList.dir/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkedList.dir/LinkedList.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hongfeizhang/Programming/ENGI-3894/LinkedList/LinkedList.cpp > CMakeFiles/LinkedList.dir/LinkedList.cpp.i

CMakeFiles/LinkedList.dir/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkedList.dir/LinkedList.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hongfeizhang/Programming/ENGI-3894/LinkedList/LinkedList.cpp -o CMakeFiles/LinkedList.dir/LinkedList.cpp.s

# Object files for target LinkedList
LinkedList_OBJECTS = \
"CMakeFiles/LinkedList.dir/LinkedList.cpp.o"

# External object files for target LinkedList
LinkedList_EXTERNAL_OBJECTS =

LinkedList: CMakeFiles/LinkedList.dir/LinkedList.cpp.o
LinkedList: CMakeFiles/LinkedList.dir/build.make
LinkedList: CMakeFiles/LinkedList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hongfeizhang/Programming/ENGI-3894/LinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LinkedList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinkedList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkedList.dir/build: LinkedList

.PHONY : CMakeFiles/LinkedList.dir/build

CMakeFiles/LinkedList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LinkedList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LinkedList.dir/clean

CMakeFiles/LinkedList.dir/depend:
	cd /Users/hongfeizhang/Programming/ENGI-3894/LinkedList/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hongfeizhang/Programming/ENGI-3894/LinkedList /Users/hongfeizhang/Programming/ENGI-3894/LinkedList /Users/hongfeizhang/Programming/ENGI-3894/LinkedList/cmake-build-debug /Users/hongfeizhang/Programming/ENGI-3894/LinkedList/cmake-build-debug /Users/hongfeizhang/Programming/ENGI-3894/LinkedList/cmake-build-debug/CMakeFiles/LinkedList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LinkedList.dir/depend

