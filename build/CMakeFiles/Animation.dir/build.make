# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.4.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.4.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mike/Documents/AnimationProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mike/Documents/AnimationProject/build

# Include any dependencies generated for this target.
include CMakeFiles/Animation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Animation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Animation.dir/flags.make

CMakeFiles/Animation.dir/main.cpp.o: CMakeFiles/Animation.dir/flags.make
CMakeFiles/Animation.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mike/Documents/AnimationProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Animation.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Animation.dir/main.cpp.o -c /Users/mike/Documents/AnimationProject/main.cpp

CMakeFiles/Animation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Animation.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mike/Documents/AnimationProject/main.cpp > CMakeFiles/Animation.dir/main.cpp.i

CMakeFiles/Animation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Animation.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mike/Documents/AnimationProject/main.cpp -o CMakeFiles/Animation.dir/main.cpp.s

CMakeFiles/Animation.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Animation.dir/main.cpp.o.requires

CMakeFiles/Animation.dir/main.cpp.o.provides: CMakeFiles/Animation.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Animation.dir/build.make CMakeFiles/Animation.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Animation.dir/main.cpp.o.provides

CMakeFiles/Animation.dir/main.cpp.o.provides.build: CMakeFiles/Animation.dir/main.cpp.o


# Object files for target Animation
Animation_OBJECTS = \
"CMakeFiles/Animation.dir/main.cpp.o"

# External object files for target Animation
Animation_EXTERNAL_OBJECTS =

Animation: CMakeFiles/Animation.dir/main.cpp.o
Animation: CMakeFiles/Animation.dir/build.make
Animation: CMakeFiles/Animation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mike/Documents/AnimationProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Animation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Animation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Animation.dir/build: Animation

.PHONY : CMakeFiles/Animation.dir/build

CMakeFiles/Animation.dir/requires: CMakeFiles/Animation.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Animation.dir/requires

CMakeFiles/Animation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Animation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Animation.dir/clean

CMakeFiles/Animation.dir/depend:
	cd /Users/mike/Documents/AnimationProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mike/Documents/AnimationProject /Users/mike/Documents/AnimationProject /Users/mike/Documents/AnimationProject/build /Users/mike/Documents/AnimationProject/build /Users/mike/Documents/AnimationProject/build/CMakeFiles/Animation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Animation.dir/depend

