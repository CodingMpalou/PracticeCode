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
CMAKE_SOURCE_DIR = "C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/flags.make

CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/main.cpp.obj: CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/flags.make
CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/main.cpp.obj"
	C:\mingw-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Pnaellhnio_Sxoliko_Diktuo.dir\main.cpp.obj -c "C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo\main.cpp"

CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/main.cpp.i"
	C:\mingw-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo\main.cpp" > CMakeFiles\Pnaellhnio_Sxoliko_Diktuo.dir\main.cpp.i

CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/main.cpp.s"
	C:\mingw-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo\main.cpp" -o CMakeFiles\Pnaellhnio_Sxoliko_Diktuo.dir\main.cpp.s

# Object files for target Pnaellhnio_Sxoliko_Diktuo
Pnaellhnio_Sxoliko_Diktuo_OBJECTS = \
"CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/main.cpp.obj"

# External object files for target Pnaellhnio_Sxoliko_Diktuo
Pnaellhnio_Sxoliko_Diktuo_EXTERNAL_OBJECTS =

Pnaellhnio_Sxoliko_Diktuo.exe: CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/main.cpp.obj
Pnaellhnio_Sxoliko_Diktuo.exe: CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/build.make
Pnaellhnio_Sxoliko_Diktuo.exe: CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/linklibs.rsp
Pnaellhnio_Sxoliko_Diktuo.exe: CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/objects1.rsp
Pnaellhnio_Sxoliko_Diktuo.exe: CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Pnaellhnio_Sxoliko_Diktuo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Pnaellhnio_Sxoliko_Diktuo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/build: Pnaellhnio_Sxoliko_Diktuo.exe

.PHONY : CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/build

CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Pnaellhnio_Sxoliko_Diktuo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/clean

CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo" "C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo" "C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo\cmake-build-debug" "C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo\cmake-build-debug" "C:\Users\zagor\CLionProjects\Pnaellhnio Sxoliko Diktuo\cmake-build-debug\CMakeFiles\Pnaellhnio_Sxoliko_Diktuo.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Pnaellhnio_Sxoliko_Diktuo.dir/depend

