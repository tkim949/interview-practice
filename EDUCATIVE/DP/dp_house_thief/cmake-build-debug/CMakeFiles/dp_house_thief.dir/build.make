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
CMAKE_SOURCE_DIR = /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dp_house_thief.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dp_house_thief.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dp_house_thief.dir/flags.make

CMakeFiles/dp_house_thief.dir/main.cpp.o: CMakeFiles/dp_house_thief.dir/flags.make
CMakeFiles/dp_house_thief.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dp_house_thief.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dp_house_thief.dir/main.cpp.o -c /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief/main.cpp

CMakeFiles/dp_house_thief.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dp_house_thief.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief/main.cpp > CMakeFiles/dp_house_thief.dir/main.cpp.i

CMakeFiles/dp_house_thief.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dp_house_thief.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief/main.cpp -o CMakeFiles/dp_house_thief.dir/main.cpp.s

# Object files for target dp_house_thief
dp_house_thief_OBJECTS = \
"CMakeFiles/dp_house_thief.dir/main.cpp.o"

# External object files for target dp_house_thief
dp_house_thief_EXTERNAL_OBJECTS =

dp_house_thief: CMakeFiles/dp_house_thief.dir/main.cpp.o
dp_house_thief: CMakeFiles/dp_house_thief.dir/build.make
dp_house_thief: CMakeFiles/dp_house_thief.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dp_house_thief"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dp_house_thief.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dp_house_thief.dir/build: dp_house_thief

.PHONY : CMakeFiles/dp_house_thief.dir/build

CMakeFiles/dp_house_thief.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dp_house_thief.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dp_house_thief.dir/clean

CMakeFiles/dp_house_thief.dir/depend:
	cd /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief/cmake-build-debug /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief/cmake-build-debug /Users/tk/Documents/Interview_Prac/EDUCATIVE/DP/dp_house_thief/cmake-build-debug/CMakeFiles/dp_house_thief.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dp_house_thief.dir/depend

