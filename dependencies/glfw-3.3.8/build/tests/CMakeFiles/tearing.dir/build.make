# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/tearing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/tearing.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/tearing.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/tearing.dir/flags.make

tests/CMakeFiles/tearing.dir/tearing.c.o: tests/CMakeFiles/tearing.dir/flags.make
tests/CMakeFiles/tearing.dir/tearing.c.o: ../tests/tearing.c
tests/CMakeFiles/tearing.dir/tearing.c.o: tests/CMakeFiles/tearing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/tearing.dir/tearing.c.o"
	cd /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/tearing.dir/tearing.c.o -MF CMakeFiles/tearing.dir/tearing.c.o.d -o CMakeFiles/tearing.dir/tearing.c.o -c /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/tests/tearing.c

tests/CMakeFiles/tearing.dir/tearing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/tearing.c.i"
	cd /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/tests/tearing.c > CMakeFiles/tearing.dir/tearing.c.i

tests/CMakeFiles/tearing.dir/tearing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/tearing.c.s"
	cd /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/tests/tearing.c -o CMakeFiles/tearing.dir/tearing.c.s

tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o: tests/CMakeFiles/tearing.dir/flags.make
tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o: ../deps/glad_gl.c
tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o: tests/CMakeFiles/tearing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o"
	cd /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o -MF CMakeFiles/tearing.dir/__/deps/glad_gl.c.o.d -o CMakeFiles/tearing.dir/__/deps/glad_gl.c.o -c /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/deps/glad_gl.c

tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tearing.dir/__/deps/glad_gl.c.i"
	cd /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/deps/glad_gl.c > CMakeFiles/tearing.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tearing.dir/__/deps/glad_gl.c.s"
	cd /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/deps/glad_gl.c -o CMakeFiles/tearing.dir/__/deps/glad_gl.c.s

# Object files for target tearing
tearing_OBJECTS = \
"CMakeFiles/tearing.dir/tearing.c.o" \
"CMakeFiles/tearing.dir/__/deps/glad_gl.c.o"

# External object files for target tearing
tearing_EXTERNAL_OBJECTS =

tests/tearing: tests/CMakeFiles/tearing.dir/tearing.c.o
tests/tearing: tests/CMakeFiles/tearing.dir/__/deps/glad_gl.c.o
tests/tearing: tests/CMakeFiles/tearing.dir/build.make
tests/tearing: src/libglfw3.a
tests/tearing: /usr/lib/x86_64-linux-gnu/libm.so
tests/tearing: /usr/lib/x86_64-linux-gnu/librt.a
tests/tearing: /usr/lib/x86_64-linux-gnu/libm.so
tests/tearing: /usr/lib/x86_64-linux-gnu/libX11.so
tests/tearing: tests/CMakeFiles/tearing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable tearing"
	cd /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tearing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/tearing.dir/build: tests/tearing
.PHONY : tests/CMakeFiles/tearing.dir/build

tests/CMakeFiles/tearing.dir/clean:
	cd /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/tearing.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/tearing.dir/clean

tests/CMakeFiles/tearing.dir/depend:
	cd /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8 /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/tests /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/tests /home/lori/cppprojects/OpenGLDemo/dependencies/glfw-3.3.8/build/tests/CMakeFiles/tearing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/tearing.dir/depend

