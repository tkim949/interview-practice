# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /Users/tk/Documents/Interview_Prac/knapsack

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tk/Documents/Interview_Prac/knapsack/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/knapsack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/knapsack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/knapsack.dir/flags.make

CMakeFiles/knapsack.dir/main.cpp.o: CMakeFiles/knapsack.dir/flags.make
CMakeFiles/knapsack.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tk/Documents/Interview_Prac/knapsack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/knapsack.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/knapsack.dir/main.cpp.o -c /Users/tk/Documents/Interview_Prac/knapsack/main.cpp

CMakeFiles/knapsack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/knapsack.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tk/Documents/Interview_Prac/knapsack/main.cpp > CMakeFiles/knapsack.dir/main.cpp.i

CMakeFiles/knapsack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/knapsack.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tk/Documents/Interview_Prac/knapsack/main.cpp -o CMakeFiles/knapsack.dir/main.cpp.s

# Object files for target knapsack
knapsack_OBJECTS = \
"CMakeFiles/knapsack.dir/main.cpp.o"

# External object files for target knapsack
knapsack_EXTERNAL_OBJECTS =

knapsack: CMakeFiles/knapsack.dir/main.cpp.o
knapsack: CMakeFiles/knapsack.dir/build.make
knapsack: CMakeFiles/knapsack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tk/Documents/Interview_Prac/knapsack/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable knapsack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/knapsack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/knapsack.dir/build: knapsack

.PHONY : CMakeFiles/knapsack.dir/build

CMakeFiles/knapsack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/knapsack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/knapsack.dir/clean

CMakeFiles/knapsack.dir/depend:
	cd /Users/tk/Documents/Interview_Prac/knapsack/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tk/Documents/Interview_Prac/knapsack /Users/tk/Documents/Interview_Prac/knapsack /Users/tk/Documents/Interview_Prac/knapsack/cmake-build-debug /Users/tk/Documents/Interview_Prac/knapsack/cmake-build-debug /Users/tk/Documents/Interview_Prac/knapsack/cmake-build-debug/CMakeFiles/knapsack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/knapsack.dir/depend

