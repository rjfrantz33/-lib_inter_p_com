# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/s0001480/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/s0001480/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/s0001480/Documents/Cpp_src/lib_inter_p_com

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/s0001480/Documents/Cpp_src/lib_inter_p_com/build

# Include any dependencies generated for this target.
include CMakeFiles/lib_inter_p_com.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lib_inter_p_com.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lib_inter_p_com.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lib_inter_p_com.dir/flags.make

CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.o: CMakeFiles/lib_inter_p_com.dir/flags.make
CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.o: /home/s0001480/Documents/Cpp_src/lib_inter_p_com/src/shared_memory.cpp
CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.o: CMakeFiles/lib_inter_p_com.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/s0001480/Documents/Cpp_src/lib_inter_p_com/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.o -MF CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.o.d -o CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.o -c /home/s0001480/Documents/Cpp_src/lib_inter_p_com/src/shared_memory.cpp

CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/s0001480/Documents/Cpp_src/lib_inter_p_com/src/shared_memory.cpp > CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.i

CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/s0001480/Documents/Cpp_src/lib_inter_p_com/src/shared_memory.cpp -o CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.s

# Object files for target lib_inter_p_com
lib_inter_p_com_OBJECTS = \
"CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.o"

# External object files for target lib_inter_p_com
lib_inter_p_com_EXTERNAL_OBJECTS =

liblib_inter_p_com.a: CMakeFiles/lib_inter_p_com.dir/src/shared_memory.cpp.o
liblib_inter_p_com.a: CMakeFiles/lib_inter_p_com.dir/build.make
liblib_inter_p_com.a: CMakeFiles/lib_inter_p_com.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/s0001480/Documents/Cpp_src/lib_inter_p_com/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblib_inter_p_com.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lib_inter_p_com.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib_inter_p_com.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lib_inter_p_com.dir/build: liblib_inter_p_com.a
.PHONY : CMakeFiles/lib_inter_p_com.dir/build

CMakeFiles/lib_inter_p_com.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lib_inter_p_com.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lib_inter_p_com.dir/clean

CMakeFiles/lib_inter_p_com.dir/depend:
	cd /home/s0001480/Documents/Cpp_src/lib_inter_p_com/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/s0001480/Documents/Cpp_src/lib_inter_p_com /home/s0001480/Documents/Cpp_src/lib_inter_p_com /home/s0001480/Documents/Cpp_src/lib_inter_p_com/build /home/s0001480/Documents/Cpp_src/lib_inter_p_com/build /home/s0001480/Documents/Cpp_src/lib_inter_p_com/build/CMakeFiles/lib_inter_p_com.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lib_inter_p_com.dir/depend

