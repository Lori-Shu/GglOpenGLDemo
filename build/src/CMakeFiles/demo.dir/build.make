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
CMAKE_SOURCE_DIR = /home/lori/CppProjects/GglOpenGLDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lori/CppProjects/GglOpenGLDemo/build

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
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/demo.dir/app.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/app.cpp.o -MF CMakeFiles/demo.dir/app.cpp.o.d -o CMakeFiles/demo.dir/app.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/app.cpp

src/CMakeFiles/demo.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/app.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/app.cpp > CMakeFiles/demo.dir/app.cpp.i

src/CMakeFiles/demo.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/app.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/app.cpp -o CMakeFiles/demo.dir/app.cpp.s

src/CMakeFiles/demo.dir/class/GglBackground.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/GglBackground.cpp.o: ../src/class/GglBackground.cpp
src/CMakeFiles/demo.dir/class/GglBackground.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/demo.dir/class/GglBackground.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/GglBackground.cpp.o -MF CMakeFiles/demo.dir/class/GglBackground.cpp.o.d -o CMakeFiles/demo.dir/class/GglBackground.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/class/GglBackground.cpp

src/CMakeFiles/demo.dir/class/GglBackground.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/GglBackground.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/class/GglBackground.cpp > CMakeFiles/demo.dir/class/GglBackground.cpp.i

src/CMakeFiles/demo.dir/class/GglBackground.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/GglBackground.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/class/GglBackground.cpp -o CMakeFiles/demo.dir/class/GglBackground.cpp.s

src/CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.o: ../src/class/GglIndexBuffer.cpp
src/CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.o -MF CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.o.d -o CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/class/GglIndexBuffer.cpp

src/CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/class/GglIndexBuffer.cpp > CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.i

src/CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/class/GglIndexBuffer.cpp -o CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.s

src/CMakeFiles/demo.dir/class/GglRenderer.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/GglRenderer.cpp.o: ../src/class/GglRenderer.cpp
src/CMakeFiles/demo.dir/class/GglRenderer.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/demo.dir/class/GglRenderer.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/GglRenderer.cpp.o -MF CMakeFiles/demo.dir/class/GglRenderer.cpp.o.d -o CMakeFiles/demo.dir/class/GglRenderer.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/class/GglRenderer.cpp

src/CMakeFiles/demo.dir/class/GglRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/GglRenderer.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/class/GglRenderer.cpp > CMakeFiles/demo.dir/class/GglRenderer.cpp.i

src/CMakeFiles/demo.dir/class/GglRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/GglRenderer.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/class/GglRenderer.cpp -o CMakeFiles/demo.dir/class/GglRenderer.cpp.s

src/CMakeFiles/demo.dir/class/GglShader.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/GglShader.cpp.o: ../src/class/GglShader.cpp
src/CMakeFiles/demo.dir/class/GglShader.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/demo.dir/class/GglShader.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/GglShader.cpp.o -MF CMakeFiles/demo.dir/class/GglShader.cpp.o.d -o CMakeFiles/demo.dir/class/GglShader.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/class/GglShader.cpp

src/CMakeFiles/demo.dir/class/GglShader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/GglShader.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/class/GglShader.cpp > CMakeFiles/demo.dir/class/GglShader.cpp.i

src/CMakeFiles/demo.dir/class/GglShader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/GglShader.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/class/GglShader.cpp -o CMakeFiles/demo.dir/class/GglShader.cpp.s

src/CMakeFiles/demo.dir/class/GglTest.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/GglTest.cpp.o: ../src/class/GglTest.cpp
src/CMakeFiles/demo.dir/class/GglTest.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/demo.dir/class/GglTest.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/GglTest.cpp.o -MF CMakeFiles/demo.dir/class/GglTest.cpp.o.d -o CMakeFiles/demo.dir/class/GglTest.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/class/GglTest.cpp

src/CMakeFiles/demo.dir/class/GglTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/GglTest.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/class/GglTest.cpp > CMakeFiles/demo.dir/class/GglTest.cpp.i

src/CMakeFiles/demo.dir/class/GglTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/GglTest.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/class/GglTest.cpp -o CMakeFiles/demo.dir/class/GglTest.cpp.s

src/CMakeFiles/demo.dir/class/GglTexture.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/GglTexture.cpp.o: ../src/class/GglTexture.cpp
src/CMakeFiles/demo.dir/class/GglTexture.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/demo.dir/class/GglTexture.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/GglTexture.cpp.o -MF CMakeFiles/demo.dir/class/GglTexture.cpp.o.d -o CMakeFiles/demo.dir/class/GglTexture.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/class/GglTexture.cpp

src/CMakeFiles/demo.dir/class/GglTexture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/GglTexture.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/class/GglTexture.cpp > CMakeFiles/demo.dir/class/GglTexture.cpp.i

src/CMakeFiles/demo.dir/class/GglTexture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/GglTexture.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/class/GglTexture.cpp -o CMakeFiles/demo.dir/class/GglTexture.cpp.s

src/CMakeFiles/demo.dir/class/GglVertexArray.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/GglVertexArray.cpp.o: ../src/class/GglVertexArray.cpp
src/CMakeFiles/demo.dir/class/GglVertexArray.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/demo.dir/class/GglVertexArray.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/GglVertexArray.cpp.o -MF CMakeFiles/demo.dir/class/GglVertexArray.cpp.o.d -o CMakeFiles/demo.dir/class/GglVertexArray.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/class/GglVertexArray.cpp

src/CMakeFiles/demo.dir/class/GglVertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/GglVertexArray.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/class/GglVertexArray.cpp > CMakeFiles/demo.dir/class/GglVertexArray.cpp.i

src/CMakeFiles/demo.dir/class/GglVertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/GglVertexArray.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/class/GglVertexArray.cpp -o CMakeFiles/demo.dir/class/GglVertexArray.cpp.s

src/CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.o: ../src/class/GglVertexBuffer.cpp
src/CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.o -MF CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.o.d -o CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/class/GglVertexBuffer.cpp

src/CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/class/GglVertexBuffer.cpp > CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.i

src/CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/class/GglVertexBuffer.cpp -o CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.s

src/CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.o: ../src/class/VertexBufferLayout.cpp
src/CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.o -MF CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.o.d -o CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/class/VertexBufferLayout.cpp

src/CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/class/VertexBufferLayout.cpp > CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.i

src/CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/class/VertexBufferLayout.cpp -o CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.s

src/CMakeFiles/demo.dir/class/stb_image_impl.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/class/stb_image_impl.cpp.o: ../src/class/stb_image_impl.cpp
src/CMakeFiles/demo.dir/class/stb_image_impl.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/demo.dir/class/stb_image_impl.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/class/stb_image_impl.cpp.o -MF CMakeFiles/demo.dir/class/stb_image_impl.cpp.o.d -o CMakeFiles/demo.dir/class/stb_image_impl.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/class/stb_image_impl.cpp

src/CMakeFiles/demo.dir/class/stb_image_impl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/class/stb_image_impl.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/class/stb_image_impl.cpp > CMakeFiles/demo.dir/class/stb_image_impl.cpp.i

src/CMakeFiles/demo.dir/class/stb_image_impl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/class/stb_image_impl.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/class/stb_image_impl.cpp -o CMakeFiles/demo.dir/class/stb_image_impl.cpp.s

src/CMakeFiles/demo.dir/imgui/imgui.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/imgui/imgui.cpp.o: ../src/imgui/imgui.cpp
src/CMakeFiles/demo.dir/imgui/imgui.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/demo.dir/imgui/imgui.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/imgui/imgui.cpp.o -MF CMakeFiles/demo.dir/imgui/imgui.cpp.o.d -o CMakeFiles/demo.dir/imgui/imgui.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui.cpp

src/CMakeFiles/demo.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/imgui/imgui.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui.cpp > CMakeFiles/demo.dir/imgui/imgui.cpp.i

src/CMakeFiles/demo.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/imgui/imgui.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui.cpp -o CMakeFiles/demo.dir/imgui/imgui.cpp.s

src/CMakeFiles/demo.dir/imgui/imgui_draw.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/imgui/imgui_draw.cpp.o: ../src/imgui/imgui_draw.cpp
src/CMakeFiles/demo.dir/imgui/imgui_draw.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/demo.dir/imgui/imgui_draw.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/imgui/imgui_draw.cpp.o -MF CMakeFiles/demo.dir/imgui/imgui_draw.cpp.o.d -o CMakeFiles/demo.dir/imgui/imgui_draw.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_draw.cpp

src/CMakeFiles/demo.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/imgui/imgui_draw.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_draw.cpp > CMakeFiles/demo.dir/imgui/imgui_draw.cpp.i

src/CMakeFiles/demo.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/imgui/imgui_draw.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_draw.cpp -o CMakeFiles/demo.dir/imgui/imgui_draw.cpp.s

src/CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.o: ../src/imgui/imgui_impl_glfw.cpp
src/CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.o -MF CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.o.d -o CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_impl_glfw.cpp

src/CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_impl_glfw.cpp > CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.i

src/CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_impl_glfw.cpp -o CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.s

src/CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.o: ../src/imgui/imgui_impl_opengl3.cpp
src/CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.o -MF CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.o.d -o CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_impl_opengl3.cpp

src/CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_impl_opengl3.cpp > CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.i

src/CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.s

src/CMakeFiles/demo.dir/imgui/imgui_tables.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/imgui/imgui_tables.cpp.o: ../src/imgui/imgui_tables.cpp
src/CMakeFiles/demo.dir/imgui/imgui_tables.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object src/CMakeFiles/demo.dir/imgui/imgui_tables.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/imgui/imgui_tables.cpp.o -MF CMakeFiles/demo.dir/imgui/imgui_tables.cpp.o.d -o CMakeFiles/demo.dir/imgui/imgui_tables.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_tables.cpp

src/CMakeFiles/demo.dir/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/imgui/imgui_tables.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_tables.cpp > CMakeFiles/demo.dir/imgui/imgui_tables.cpp.i

src/CMakeFiles/demo.dir/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/imgui/imgui_tables.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_tables.cpp -o CMakeFiles/demo.dir/imgui/imgui_tables.cpp.s

src/CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.o: src/CMakeFiles/demo.dir/flags.make
src/CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.o: ../src/imgui/imgui_widgets.cpp
src/CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.o: src/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object src/CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.o"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.o -MF CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.o -c /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_widgets.cpp

src/CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.i"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_widgets.cpp > CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.i

src/CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.s"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lori/CppProjects/GglOpenGLDemo/src/imgui/imgui_widgets.cpp -o CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/app.cpp.o" \
"CMakeFiles/demo.dir/class/GglBackground.cpp.o" \
"CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.o" \
"CMakeFiles/demo.dir/class/GglRenderer.cpp.o" \
"CMakeFiles/demo.dir/class/GglShader.cpp.o" \
"CMakeFiles/demo.dir/class/GglTest.cpp.o" \
"CMakeFiles/demo.dir/class/GglTexture.cpp.o" \
"CMakeFiles/demo.dir/class/GglVertexArray.cpp.o" \
"CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.o" \
"CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.o" \
"CMakeFiles/demo.dir/class/stb_image_impl.cpp.o" \
"CMakeFiles/demo.dir/imgui/imgui.cpp.o" \
"CMakeFiles/demo.dir/imgui/imgui_draw.cpp.o" \
"CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.o" \
"CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/demo.dir/imgui/imgui_tables.cpp.o" \
"CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

../bin/demo: src/CMakeFiles/demo.dir/app.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/GglBackground.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/GglIndexBuffer.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/GglRenderer.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/GglShader.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/GglTest.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/GglTexture.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/GglVertexArray.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/GglVertexBuffer.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/VertexBufferLayout.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/class/stb_image_impl.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/imgui/imgui.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/imgui/imgui_draw.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/imgui/imgui_impl_glfw.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/imgui/imgui_impl_opengl3.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/imgui/imgui_tables.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/imgui/imgui_widgets.cpp.o
../bin/demo: src/CMakeFiles/demo.dir/build.make
../bin/demo: src/CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lori/CppProjects/GglOpenGLDemo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable ../../bin/demo"
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/demo.dir/build: ../bin/demo
.PHONY : src/CMakeFiles/demo.dir/build

src/CMakeFiles/demo.dir/clean:
	cd /home/lori/CppProjects/GglOpenGLDemo/build/src && $(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/demo.dir/clean

src/CMakeFiles/demo.dir/depend:
	cd /home/lori/CppProjects/GglOpenGLDemo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lori/CppProjects/GglOpenGLDemo /home/lori/CppProjects/GglOpenGLDemo/src /home/lori/CppProjects/GglOpenGLDemo/build /home/lori/CppProjects/GglOpenGLDemo/build/src /home/lori/CppProjects/GglOpenGLDemo/build/src/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/demo.dir/depend

