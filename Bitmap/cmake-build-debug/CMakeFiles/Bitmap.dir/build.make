# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /Users/me/CLionProjects/Bitmap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/me/CLionProjects/Bitmap/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Bitmap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bitmap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bitmap.dir/flags.make

CMakeFiles/Bitmap.dir/main.cpp.o: CMakeFiles/Bitmap.dir/flags.make
CMakeFiles/Bitmap.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/me/CLionProjects/Bitmap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bitmap.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bitmap.dir/main.cpp.o -c /Users/me/CLionProjects/Bitmap/main.cpp

CMakeFiles/Bitmap.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bitmap.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/me/CLionProjects/Bitmap/main.cpp > CMakeFiles/Bitmap.dir/main.cpp.i

CMakeFiles/Bitmap.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bitmap.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/me/CLionProjects/Bitmap/main.cpp -o CMakeFiles/Bitmap.dir/main.cpp.s

CMakeFiles/Bitmap.dir/Bitmap.cpp.o: CMakeFiles/Bitmap.dir/flags.make
CMakeFiles/Bitmap.dir/Bitmap.cpp.o: ../Bitmap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/me/CLionProjects/Bitmap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Bitmap.dir/Bitmap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bitmap.dir/Bitmap.cpp.o -c /Users/me/CLionProjects/Bitmap/Bitmap.cpp

CMakeFiles/Bitmap.dir/Bitmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bitmap.dir/Bitmap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/me/CLionProjects/Bitmap/Bitmap.cpp > CMakeFiles/Bitmap.dir/Bitmap.cpp.i

CMakeFiles/Bitmap.dir/Bitmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bitmap.dir/Bitmap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/me/CLionProjects/Bitmap/Bitmap.cpp -o CMakeFiles/Bitmap.dir/Bitmap.cpp.s

# Object files for target Bitmap
Bitmap_OBJECTS = \
"CMakeFiles/Bitmap.dir/main.cpp.o" \
"CMakeFiles/Bitmap.dir/Bitmap.cpp.o"

# External object files for target Bitmap
Bitmap_EXTERNAL_OBJECTS =

Bitmap: CMakeFiles/Bitmap.dir/main.cpp.o
Bitmap: CMakeFiles/Bitmap.dir/Bitmap.cpp.o
Bitmap: CMakeFiles/Bitmap.dir/build.make
Bitmap: CMakeFiles/Bitmap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/me/CLionProjects/Bitmap/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Bitmap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bitmap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bitmap.dir/build: Bitmap

.PHONY : CMakeFiles/Bitmap.dir/build

CMakeFiles/Bitmap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bitmap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bitmap.dir/clean

CMakeFiles/Bitmap.dir/depend:
	cd /Users/me/CLionProjects/Bitmap/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/me/CLionProjects/Bitmap /Users/me/CLionProjects/Bitmap /Users/me/CLionProjects/Bitmap/cmake-build-debug /Users/me/CLionProjects/Bitmap/cmake-build-debug /Users/me/CLionProjects/Bitmap/cmake-build-debug/CMakeFiles/Bitmap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bitmap.dir/depend

