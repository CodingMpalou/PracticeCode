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
CMAKE_SOURCE_DIR = C:\Users\zagor\CLionProjects\Croatian_Lutrija

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\zagor\CLionProjects\Croatian_Lutrija\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Croatian_Lutrija.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Croatian_Lutrija.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Croatian_Lutrija.dir/flags.make

CMakeFiles/Croatian_Lutrija.dir/main.cpp.obj: CMakeFiles/Croatian_Lutrija.dir/flags.make
CMakeFiles/Croatian_Lutrija.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\zagor\CLionProjects\Croatian_Lutrija\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Croatian_Lutrija.dir/main.cpp.obj"
	C:\mingw-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Croatian_Lutrija.dir\main.cpp.obj -c C:\Users\zagor\CLionProjects\Croatian_Lutrija\main.cpp

CMakeFiles/Croatian_Lutrija.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Croatian_Lutrija.dir/main.cpp.i"
	C:\mingw-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\zagor\CLionProjects\Croatian_Lutrija\main.cpp > CMakeFiles\Croatian_Lutrija.dir\main.cpp.i

CMakeFiles/Croatian_Lutrija.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Croatian_Lutrija.dir/main.cpp.s"
	C:\mingw-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\zagor\CLionProjects\Croatian_Lutrija\main.cpp -o CMakeFiles\Croatian_Lutrija.dir\main.cpp.s

# Object files for target Croatian_Lutrija
Croatian_Lutrija_OBJECTS = \
"CMakeFiles/Croatian_Lutrija.dir/main.cpp.obj"

# External object files for target Croatian_Lutrija
Croatian_Lutrija_EXTERNAL_OBJECTS =

Croatian_Lutrija.exe: CMakeFiles/Croatian_Lutrija.dir/main.cpp.obj
Croatian_Lutrija.exe: CMakeFiles/Croatian_Lutrija.dir/build.make
Croatian_Lutrija.exe: CMakeFiles/Croatian_Lutrija.dir/linklibs.rsp
Croatian_Lutrija.exe: CMakeFiles/Croatian_Lutrija.dir/objects1.rsp
Croatian_Lutrija.exe: CMakeFiles/Croatian_Lutrija.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\zagor\CLionProjects\Croatian_Lutrija\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Croatian_Lutrija.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Croatian_Lutrija.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Croatian_Lutrija.dir/build: Croatian_Lutrija.exe

.PHONY : CMakeFiles/Croatian_Lutrija.dir/build

CMakeFiles/Croatian_Lutrija.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Croatian_Lutrija.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Croatian_Lutrija.dir/clean

CMakeFiles/Croatian_Lutrija.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\zagor\CLionProjects\Croatian_Lutrija C:\Users\zagor\CLionProjects\Croatian_Lutrija C:\Users\zagor\CLionProjects\Croatian_Lutrija\cmake-build-debug C:\Users\zagor\CLionProjects\Croatian_Lutrija\cmake-build-debug C:\Users\zagor\CLionProjects\Croatian_Lutrija\cmake-build-debug\CMakeFiles\Croatian_Lutrija.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Croatian_Lutrija.dir/depend

