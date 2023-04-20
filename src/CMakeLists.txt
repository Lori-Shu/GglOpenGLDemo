include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/dependencies/glm)

find_package(glfw3 REQUIRED)

find_package(OpenGL REQUIRED)

file(GLOB cppFiles 
${PROJECT_SOURCE_DIR}/src/imgui/*.cpp
${PROJECT_SOURCE_DIR}/src/*.cpp 
${PROJECT_SOURCE_DIR}/src/class/*.cpp)



set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(demo ${cppFiles})

target_link_libraries(demo GL glfw3 GLEW X11)

exec_program(cp ARGS -r ${PROJECT_SOURCE_DIR}/src/shader/ ${PROJECT_SOURCE_DIR}/bin/)