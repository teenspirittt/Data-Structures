# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_SOURCE_DIR = /home/teenspirit/NSTU/AADS/1_lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/teenspirit/NSTU/AADS/1_lab/build

# Include any dependencies generated for this target.
include CMakeFiles/CycListTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CycListTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CycListTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CycListTests.dir/flags.make

CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.o: CMakeFiles/CycListTests.dir/flags.make
CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.o: /home/teenspirit/NSTU/AADS/1_lab/tests/CycListTests.cpp
CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.o: CMakeFiles/CycListTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teenspirit/NSTU/AADS/1_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.o -MF CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.o.d -o CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.o -c /home/teenspirit/NSTU/AADS/1_lab/tests/CycListTests.cpp

CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teenspirit/NSTU/AADS/1_lab/tests/CycListTests.cpp > CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.i

CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teenspirit/NSTU/AADS/1_lab/tests/CycListTests.cpp -o CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.s

CMakeFiles/CycListTests.dir/src/CycList.cpp.o: CMakeFiles/CycListTests.dir/flags.make
CMakeFiles/CycListTests.dir/src/CycList.cpp.o: /home/teenspirit/NSTU/AADS/1_lab/src/CycList.cpp
CMakeFiles/CycListTests.dir/src/CycList.cpp.o: CMakeFiles/CycListTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teenspirit/NSTU/AADS/1_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CycListTests.dir/src/CycList.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CycListTests.dir/src/CycList.cpp.o -MF CMakeFiles/CycListTests.dir/src/CycList.cpp.o.d -o CMakeFiles/CycListTests.dir/src/CycList.cpp.o -c /home/teenspirit/NSTU/AADS/1_lab/src/CycList.cpp

CMakeFiles/CycListTests.dir/src/CycList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CycListTests.dir/src/CycList.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teenspirit/NSTU/AADS/1_lab/src/CycList.cpp > CMakeFiles/CycListTests.dir/src/CycList.cpp.i

CMakeFiles/CycListTests.dir/src/CycList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CycListTests.dir/src/CycList.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teenspirit/NSTU/AADS/1_lab/src/CycList.cpp -o CMakeFiles/CycListTests.dir/src/CycList.cpp.s

CMakeFiles/CycListTests.dir/src/menu.cpp.o: CMakeFiles/CycListTests.dir/flags.make
CMakeFiles/CycListTests.dir/src/menu.cpp.o: /home/teenspirit/NSTU/AADS/1_lab/src/menu.cpp
CMakeFiles/CycListTests.dir/src/menu.cpp.o: CMakeFiles/CycListTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teenspirit/NSTU/AADS/1_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CycListTests.dir/src/menu.cpp.o"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CycListTests.dir/src/menu.cpp.o -MF CMakeFiles/CycListTests.dir/src/menu.cpp.o.d -o CMakeFiles/CycListTests.dir/src/menu.cpp.o -c /home/teenspirit/NSTU/AADS/1_lab/src/menu.cpp

CMakeFiles/CycListTests.dir/src/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CycListTests.dir/src/menu.cpp.i"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teenspirit/NSTU/AADS/1_lab/src/menu.cpp > CMakeFiles/CycListTests.dir/src/menu.cpp.i

CMakeFiles/CycListTests.dir/src/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CycListTests.dir/src/menu.cpp.s"
	/usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teenspirit/NSTU/AADS/1_lab/src/menu.cpp -o CMakeFiles/CycListTests.dir/src/menu.cpp.s

# Object files for target CycListTests
CycListTests_OBJECTS = \
"CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.o" \
"CMakeFiles/CycListTests.dir/src/CycList.cpp.o" \
"CMakeFiles/CycListTests.dir/src/menu.cpp.o"

# External object files for target CycListTests
CycListTests_EXTERNAL_OBJECTS =

CycListTests: CMakeFiles/CycListTests.dir/tests/CycListTests.cpp.o
CycListTests: CMakeFiles/CycListTests.dir/src/CycList.cpp.o
CycListTests: CMakeFiles/CycListTests.dir/src/menu.cpp.o
CycListTests: CMakeFiles/CycListTests.dir/build.make
CycListTests: lib/libgtest.a
CycListTests: CMakeFiles/CycListTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/teenspirit/NSTU/AADS/1_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CycListTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CycListTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CycListTests.dir/build: CycListTests
.PHONY : CMakeFiles/CycListTests.dir/build

CMakeFiles/CycListTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CycListTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CycListTests.dir/clean

CMakeFiles/CycListTests.dir/depend:
	cd /home/teenspirit/NSTU/AADS/1_lab/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/teenspirit/NSTU/AADS/1_lab /home/teenspirit/NSTU/AADS/1_lab /home/teenspirit/NSTU/AADS/1_lab/build /home/teenspirit/NSTU/AADS/1_lab/build /home/teenspirit/NSTU/AADS/1_lab/build/CMakeFiles/CycListTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CycListTests.dir/depend
