# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daniel/Downloads/myterm/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniel/Downloads/myterm/bin

# Include any dependencies generated for this target.
include CMakeFiles/lab1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab1.dir/flags.make

CMakeFiles/lab1.dir/shell.cxx.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/shell.cxx.o: /home/daniel/Downloads/myterm/src/shell.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/daniel/Downloads/myterm/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab1.dir/shell.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab1.dir/shell.cxx.o -c /home/daniel/Downloads/myterm/src/shell.cxx

CMakeFiles/lab1.dir/shell.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1.dir/shell.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/daniel/Downloads/myterm/src/shell.cxx > CMakeFiles/lab1.dir/shell.cxx.i

CMakeFiles/lab1.dir/shell.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1.dir/shell.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/daniel/Downloads/myterm/src/shell.cxx -o CMakeFiles/lab1.dir/shell.cxx.s

CMakeFiles/lab1.dir/shell.cxx.o.requires:
.PHONY : CMakeFiles/lab1.dir/shell.cxx.o.requires

CMakeFiles/lab1.dir/shell.cxx.o.provides: CMakeFiles/lab1.dir/shell.cxx.o.requires
	$(MAKE) -f CMakeFiles/lab1.dir/build.make CMakeFiles/lab1.dir/shell.cxx.o.provides.build
.PHONY : CMakeFiles/lab1.dir/shell.cxx.o.provides

CMakeFiles/lab1.dir/shell.cxx.o.provides.build: CMakeFiles/lab1.dir/shell.cxx.o

CMakeFiles/lab1.dir/command.cxx.o: CMakeFiles/lab1.dir/flags.make
CMakeFiles/lab1.dir/command.cxx.o: /home/daniel/Downloads/myterm/src/command.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/daniel/Downloads/myterm/bin/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/lab1.dir/command.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lab1.dir/command.cxx.o -c /home/daniel/Downloads/myterm/src/command.cxx

CMakeFiles/lab1.dir/command.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab1.dir/command.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/daniel/Downloads/myterm/src/command.cxx > CMakeFiles/lab1.dir/command.cxx.i

CMakeFiles/lab1.dir/command.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab1.dir/command.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/daniel/Downloads/myterm/src/command.cxx -o CMakeFiles/lab1.dir/command.cxx.s

CMakeFiles/lab1.dir/command.cxx.o.requires:
.PHONY : CMakeFiles/lab1.dir/command.cxx.o.requires

CMakeFiles/lab1.dir/command.cxx.o.provides: CMakeFiles/lab1.dir/command.cxx.o.requires
	$(MAKE) -f CMakeFiles/lab1.dir/build.make CMakeFiles/lab1.dir/command.cxx.o.provides.build
.PHONY : CMakeFiles/lab1.dir/command.cxx.o.provides

CMakeFiles/lab1.dir/command.cxx.o.provides.build: CMakeFiles/lab1.dir/command.cxx.o

# Object files for target lab1
lab1_OBJECTS = \
"CMakeFiles/lab1.dir/shell.cxx.o" \
"CMakeFiles/lab1.dir/command.cxx.o"

# External object files for target lab1
lab1_EXTERNAL_OBJECTS =

lab1: CMakeFiles/lab1.dir/shell.cxx.o
lab1: CMakeFiles/lab1.dir/command.cxx.o
lab1: CMakeFiles/lab1.dir/build.make
lab1: CMakeFiles/lab1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable lab1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab1.dir/build: lab1
.PHONY : CMakeFiles/lab1.dir/build

CMakeFiles/lab1.dir/requires: CMakeFiles/lab1.dir/shell.cxx.o.requires
CMakeFiles/lab1.dir/requires: CMakeFiles/lab1.dir/command.cxx.o.requires
.PHONY : CMakeFiles/lab1.dir/requires

CMakeFiles/lab1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab1.dir/clean

CMakeFiles/lab1.dir/depend:
	cd /home/daniel/Downloads/myterm/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniel/Downloads/myterm/src /home/daniel/Downloads/myterm/src /home/daniel/Downloads/myterm/bin /home/daniel/Downloads/myterm/bin /home/daniel/Downloads/myterm/bin/CMakeFiles/lab1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab1.dir/depend

