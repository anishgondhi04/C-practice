# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/unzipper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unzipper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unzipper.dir/flags.make

CMakeFiles/unzipper.dir/main.c.o: CMakeFiles/unzipper.dir/flags.make
CMakeFiles/unzipper.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/unzipper.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/unzipper.dir/main.c.o -c /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper/main.c

CMakeFiles/unzipper.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unzipper.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper/main.c > CMakeFiles/unzipper.dir/main.c.i

CMakeFiles/unzipper.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unzipper.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper/main.c -o CMakeFiles/unzipper.dir/main.c.s

# Object files for target unzipper
unzipper_OBJECTS = \
"CMakeFiles/unzipper.dir/main.c.o"

# External object files for target unzipper
unzipper_EXTERNAL_OBJECTS =

unzipper: CMakeFiles/unzipper.dir/main.c.o
unzipper: CMakeFiles/unzipper.dir/build.make
unzipper: CMakeFiles/unzipper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable unzipper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unzipper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unzipper.dir/build: unzipper

.PHONY : CMakeFiles/unzipper.dir/build

CMakeFiles/unzipper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unzipper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unzipper.dir/clean

CMakeFiles/unzipper.dir/depend:
	cd /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper/cmake-build-debug /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper/cmake-build-debug /users/cs/gondhi/tmp/tmp.VGDqTLttai/unzipper/cmake-build-debug/CMakeFiles/unzipper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unzipper.dir/depend
