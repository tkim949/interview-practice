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
CMAKE_SOURCE_DIR = /Users/tk/Documents/Interview_Prac/fruit_promo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tk/Documents/Interview_Prac/fruit_promo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fruit_promo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fruit_promo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fruit_promo.dir/flags.make

CMakeFiles/fruit_promo.dir/main.cpp.o: CMakeFiles/fruit_promo.dir/flags.make
CMakeFiles/fruit_promo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tk/Documents/Interview_Prac/fruit_promo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fruit_promo.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fruit_promo.dir/main.cpp.o -c /Users/tk/Documents/Interview_Prac/fruit_promo/main.cpp

CMakeFiles/fruit_promo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fruit_promo.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tk/Documents/Interview_Prac/fruit_promo/main.cpp > CMakeFiles/fruit_promo.dir/main.cpp.i

CMakeFiles/fruit_promo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fruit_promo.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tk/Documents/Interview_Prac/fruit_promo/main.cpp -o CMakeFiles/fruit_promo.dir/main.cpp.s

# Object files for target fruit_promo
fruit_promo_OBJECTS = \
"CMakeFiles/fruit_promo.dir/main.cpp.o"

# External object files for target fruit_promo
fruit_promo_EXTERNAL_OBJECTS =

fruit_promo: CMakeFiles/fruit_promo.dir/main.cpp.o
fruit_promo: CMakeFiles/fruit_promo.dir/build.make
fruit_promo: CMakeFiles/fruit_promo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tk/Documents/Interview_Prac/fruit_promo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fruit_promo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fruit_promo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fruit_promo.dir/build: fruit_promo

.PHONY : CMakeFiles/fruit_promo.dir/build

CMakeFiles/fruit_promo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fruit_promo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fruit_promo.dir/clean

CMakeFiles/fruit_promo.dir/depend:
	cd /Users/tk/Documents/Interview_Prac/fruit_promo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tk/Documents/Interview_Prac/fruit_promo /Users/tk/Documents/Interview_Prac/fruit_promo /Users/tk/Documents/Interview_Prac/fruit_promo/cmake-build-debug /Users/tk/Documents/Interview_Prac/fruit_promo/cmake-build-debug /Users/tk/Documents/Interview_Prac/fruit_promo/cmake-build-debug/CMakeFiles/fruit_promo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fruit_promo.dir/depend

