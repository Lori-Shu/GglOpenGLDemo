include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/dependencies/glmrepo 
${PROJECT_SOURCE_DIR}/dependencies/glfwbin/include ${PROJECT_SOURCE_DIR}/dependencies/curl-mingw/include
)


file(GLOB cppFiles 

${PROJECT_SOURCE_DIR}/src/*.cpp 
${PROJECT_SOURCE_DIR}/src/*.c 
${PROJECT_SOURCE_DIR}/src/class/*.cpp
${PROJECT_SOURCE_DIR}/src/imgui/*.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/dependencies/glfwbin/lib ${PROJECT_SOURCE_DIR}/dependencies/curl-mingw/lib)

add_executable(demo ${cppFiles})

target_link_libraries(demo  glfw3 curl)


exec_program(xcopy ${PROJECT_SOURCE_DIR}/src/shader ${PROJECT_SOURCE_DIR}/bin)