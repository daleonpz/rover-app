# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/rover-app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/rover-app/build

# Include any dependencies generated for this target.
include CMakeFiles/status_library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/status_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/status_library.dir/flags.make

CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o: CMakeFiles/status_library.dir/flags.make
CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o: ../src/libraries/status_library/status_library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rover-app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o -c /home/pi/rover-app/src/libraries/status_library/status_library.cpp

CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/rover-app/src/libraries/status_library/status_library.cpp > CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.i

CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/rover-app/src/libraries/status_library/status_library.cpp -o CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.s

CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o.requires:

.PHONY : CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o.requires

CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o.provides: CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o.requires
	$(MAKE) -f CMakeFiles/status_library.dir/build.make CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o.provides.build
.PHONY : CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o.provides

CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o.provides.build: CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o


# Object files for target status_library
status_library_OBJECTS = \
"CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o"

# External object files for target status_library
status_library_EXTERNAL_OBJECTS =

libs/libstatus_library.so: CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o
libs/libstatus_library.so: CMakeFiles/status_library.dir/build.make
libs/libstatus_library.so: CMakeFiles/status_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/rover-app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libs/libstatus_library.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/status_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/status_library.dir/build: libs/libstatus_library.so

.PHONY : CMakeFiles/status_library.dir/build

CMakeFiles/status_library.dir/requires: CMakeFiles/status_library.dir/src/libraries/status_library/status_library.cpp.o.requires

.PHONY : CMakeFiles/status_library.dir/requires

CMakeFiles/status_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/status_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/status_library.dir/clean

CMakeFiles/status_library.dir/depend:
	cd /home/pi/rover-app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/rover-app /home/pi/rover-app /home/pi/rover-app/build /home/pi/rover-app/build /home/pi/rover-app/build/CMakeFiles/status_library.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/status_library.dir/depend
