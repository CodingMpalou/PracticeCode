# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\zagor\CLionProjects\out

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\zagor\CLionProjects\out\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/out.dir/flags.make

CMakeFiles/out.dir/main.cpp.obj: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zagor\CLionProjects\out\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/out.dir/main.cpp.obj"
	C:\mingw-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\out.dir\main.cpp.obj -c C:\Users\zagor\CLionProjects\out\main.cpp

CMakeFiles/out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/main.cpp.i"
	C:\mingw-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zagor\CLionProjects\out\main.cpp > CMakeFiles\out.dir\main.cpp.i

CMakeFiles/out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/main.cpp.s"
	C:\mingw-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zagor\CLionProjects\out\main.cpp -o CMakeFiles\out.dir\main.cpp.s

# Object files for target out
out_OBJECTS = \
"CMakeFiles/out.dir/main.cpp.obj"

# External object files for target out
out_EXTERNAL_OBJECTS =

out.exe: CMakeFiles/out.dir/main.cpp.obj
out.exe: CMakeFiles/out.dir/build.make
out.exe: CMakeFiles/out.dir/linklibs.rsp
out.exe: CMakeFiles/out.dir/objects1.rsp
out.exe: CMakeFiles/out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\zagor\CLionProjects\out\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable out.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\out.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/out.dir/build: out.exe

.PHONY : CMakeFiles/out.dir/build

CMakeFiles/out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\out.dir\cmake_clean.cmake
.PHONY : CMakeFiles/out.dir/clean

CMakeFiles/out.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\zagor\CLionProjects\out C:\Users\zagor\CLionProjects\out C:\Users\zagor\CLionProjects\out\cmake-build-debug C:\Users\zagor\CLionProjects\out\cmake-build-debug C:\Users\zagor\CLionProjects\out\cmake-build-debug\CMakeFiles\out.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/out.dir/depend

