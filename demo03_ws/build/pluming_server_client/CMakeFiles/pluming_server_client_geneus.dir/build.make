# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/xdh/demo03_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xdh/demo03_ws/build

# Utility rule file for pluming_server_client_geneus.

# Include the progress variables for this target.
include pluming_server_client/CMakeFiles/pluming_server_client_geneus.dir/progress.make

pluming_server_client_geneus: pluming_server_client/CMakeFiles/pluming_server_client_geneus.dir/build.make

.PHONY : pluming_server_client_geneus

# Rule to build all files generated by this target.
pluming_server_client/CMakeFiles/pluming_server_client_geneus.dir/build: pluming_server_client_geneus

.PHONY : pluming_server_client/CMakeFiles/pluming_server_client_geneus.dir/build

pluming_server_client/CMakeFiles/pluming_server_client_geneus.dir/clean:
	cd /home/xdh/demo03_ws/build/pluming_server_client && $(CMAKE_COMMAND) -P CMakeFiles/pluming_server_client_geneus.dir/cmake_clean.cmake
.PHONY : pluming_server_client/CMakeFiles/pluming_server_client_geneus.dir/clean

pluming_server_client/CMakeFiles/pluming_server_client_geneus.dir/depend:
	cd /home/xdh/demo03_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xdh/demo03_ws/src /home/xdh/demo03_ws/src/pluming_server_client /home/xdh/demo03_ws/build /home/xdh/demo03_ws/build/pluming_server_client /home/xdh/demo03_ws/build/pluming_server_client/CMakeFiles/pluming_server_client_geneus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pluming_server_client/CMakeFiles/pluming_server_client_geneus.dir/depend

