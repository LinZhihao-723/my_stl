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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/renaissance/Desktop/my_stl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/renaissance/Desktop/my_stl/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_stl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_stl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_stl.dir/flags.make

CMakeFiles/my_stl.dir/main.cpp.o: CMakeFiles/my_stl.dir/flags.make
CMakeFiles/my_stl.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renaissance/Desktop/my_stl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_stl.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_stl.dir/main.cpp.o -c /Users/renaissance/Desktop/my_stl/main.cpp

CMakeFiles/my_stl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_stl.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/renaissance/Desktop/my_stl/main.cpp > CMakeFiles/my_stl.dir/main.cpp.i

CMakeFiles/my_stl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_stl.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/renaissance/Desktop/my_stl/main.cpp -o CMakeFiles/my_stl.dir/main.cpp.s

CMakeFiles/my_stl.dir/stack.cpp.o: CMakeFiles/my_stl.dir/flags.make
CMakeFiles/my_stl.dir/stack.cpp.o: ../stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/renaissance/Desktop/my_stl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_stl.dir/stack.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_stl.dir/stack.cpp.o -c /Users/renaissance/Desktop/my_stl/stack.cpp

CMakeFiles/my_stl.dir/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_stl.dir/stack.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/renaissance/Desktop/my_stl/stack.cpp > CMakeFiles/my_stl.dir/stack.cpp.i

CMakeFiles/my_stl.dir/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_stl.dir/stack.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/renaissance/Desktop/my_stl/stack.cpp -o CMakeFiles/my_stl.dir/stack.cpp.s

# Object files for target my_stl
my_stl_OBJECTS = \
"CMakeFiles/my_stl.dir/main.cpp.o" \
"CMakeFiles/my_stl.dir/stack.cpp.o"

# External object files for target my_stl
my_stl_EXTERNAL_OBJECTS =

my_stl: CMakeFiles/my_stl.dir/main.cpp.o
my_stl: CMakeFiles/my_stl.dir/stack.cpp.o
my_stl: CMakeFiles/my_stl.dir/build.make
my_stl: CMakeFiles/my_stl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/renaissance/Desktop/my_stl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable my_stl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_stl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_stl.dir/build: my_stl

.PHONY : CMakeFiles/my_stl.dir/build

CMakeFiles/my_stl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_stl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_stl.dir/clean

CMakeFiles/my_stl.dir/depend:
	cd /Users/renaissance/Desktop/my_stl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/renaissance/Desktop/my_stl /Users/renaissance/Desktop/my_stl /Users/renaissance/Desktop/my_stl/cmake-build-debug /Users/renaissance/Desktop/my_stl/cmake-build-debug /Users/renaissance/Desktop/my_stl/cmake-build-debug/CMakeFiles/my_stl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_stl.dir/depend

