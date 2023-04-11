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
CMAKE_SOURCE_DIR = /home/lori/cppprojects/OpenGLDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lori/cppprojects/OpenGLDemo/build

# Include any dependencies generated for this target.
include src/CMakeFiles/demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/demo.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/demo.dir/flags.make

src/CMakeFiles/demo.dir/app.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/app.cpp.o: ../src/app.cpp
src/CMakeFiles/demo.dir/app.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/cppprojects/OpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/demo.dir/app.cpp.o"
	cd /home/lori/cppprojects/OpenGLDemo/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/app.cpp.o -MF CMakeFiles/demo.dir/app.cpp.o.d -o CMakeFiles/demo.dir/app.cpp.o -c /home/lori/cppprojects/OpenGLDemo/src/app.cpp

src/CMakeFiles/demo.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/app.cpp.i"
	cd /home/lori/cppprojects/OpenGLDemo/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/cppprojects/OpenGLDemo/src/app.cpp > CMakeFiles/demo.dir/app.cpp.i

src/CMakeFiles/demo.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/app.cpp.s"
	cd /home/lori/cppprojects/OpenGLDemo/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/cppprojects/OpenGLDemo/src/app.cpp -o CMakeFiles/demo.dir/app.cpp.s

src/CMakeFiles/demo.dir/class/GglShader.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/GglShader.cpp.o: ../src/class/GglShader.cpp
src/CMakeFiles/demo.dir/class/GglShader.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/cppprojects/OpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/demo.dir/class/GglShader.cpp.o"
	cd /home/lori/cppprojects/OpenGLDemo/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/GglShader.cpp.o -MF CMakeFiles/demo.dir/class/GglShader.cpp.o.d -o CMakeFiles/demo.dir/class/GglShader.cpp.o -c /home/lori/cppprojects/OpenGLDemo/src/class/GglShader.cpp

src/CMakeFiles/demo.dir/class/GglShader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/GglShader.cpp.i"
	cd /home/lori/cppprojects/OpenGLDemo/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/cppprojects/OpenGLDemo/src/class/GglShader.cpp > CMakeFiles/demo.dir/class/GglShader.cpp.i

src/CMakeFiles/demo.dir/class/GglShader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/GglShader.cpp.s"
	cd /home/lori/cppprojects/OpenGLDemo/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/cppprojects/OpenGLDemo/src/class/GglShader.cpp -o CMakeFiles/demo.dir/class/GglShader.cpp.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/app.cpp.o" \
"CMakeFiles/demo.dir/class/GglShader.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

../bin/demo: src/CMakeFiles/demo.dir/app.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/GglShader.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/build.make
../bin/demo: src/CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lori/cppprojects/OpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/demo"
	cd /home/lori/cppprojects/OpenGLDemo/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/demo.dir/build: ../bin/demo
.PHONY : src/CMakeFiles/demo.dir/build

src/CMakeFiles/demo.dir/clean:
	cd /home/lori/cppprojects/OpenGLDemo/build/src && $(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/demo.dir/clean

src/CMakeFiles/demo.dir/depend:
	cd /home/lori/cppprojects/OpenGLDemo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lori/cppprojects/OpenGLDemo /home/lori/cppprojects/OpenGLDemo/src /home/lori/cppprojects/OpenGLDemo/build /home/lori/cppprojects/OpenGLDemo/build/src /home/lori/cppprojects/OpenGLDemo/build/src/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/demo.dir/depend
