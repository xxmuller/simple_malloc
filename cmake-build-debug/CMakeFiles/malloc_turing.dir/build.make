# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\FIIT\DSA\malloc_turing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\FIIT\DSA\malloc_turing\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/malloc_turing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/malloc_turing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/malloc_turing.dir/flags.make

CMakeFiles/malloc_turing.dir/main.c.obj: CMakeFiles/malloc_turing.dir/flags.make
CMakeFiles/malloc_turing.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\FIIT\DSA\malloc_turing\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/malloc_turing.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\malloc_turing.dir\main.c.obj   -c C:\FIIT\DSA\malloc_turing\main.c

CMakeFiles/malloc_turing.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc_turing.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\FIIT\DSA\malloc_turing\main.c > CMakeFiles\malloc_turing.dir\main.c.i

CMakeFiles/malloc_turing.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc_turing.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\FIIT\DSA\malloc_turing\main.c -o CMakeFiles\malloc_turing.dir\main.c.s

# Object files for target malloc_turing
malloc_turing_OBJECTS = \
"CMakeFiles/malloc_turing.dir/main.c.obj"

# External object files for target malloc_turing
malloc_turing_EXTERNAL_OBJECTS =

malloc_turing.exe: CMakeFiles/malloc_turing.dir/main.c.obj
malloc_turing.exe: CMakeFiles/malloc_turing.dir/build.make
malloc_turing.exe: CMakeFiles/malloc_turing.dir/linklibs.rsp
malloc_turing.exe: CMakeFiles/malloc_turing.dir/objects1.rsp
malloc_turing.exe: CMakeFiles/malloc_turing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\FIIT\DSA\malloc_turing\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable malloc_turing.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\malloc_turing.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/malloc_turing.dir/build: malloc_turing.exe

.PHONY : CMakeFiles/malloc_turing.dir/build

CMakeFiles/malloc_turing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\malloc_turing.dir\cmake_clean.cmake
.PHONY : CMakeFiles/malloc_turing.dir/clean

CMakeFiles/malloc_turing.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\FIIT\DSA\malloc_turing C:\FIIT\DSA\malloc_turing C:\FIIT\DSA\malloc_turing\cmake-build-debug C:\FIIT\DSA\malloc_turing\cmake-build-debug C:\FIIT\DSA\malloc_turing\cmake-build-debug\CMakeFiles\malloc_turing.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/malloc_turing.dir/depend

