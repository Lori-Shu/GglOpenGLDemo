include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/dependencies/glmrepo 
${PROJECT_SOURCE_DIR}/dependencies/glfwbin/include ${PROJECT_SOURCE_DIR}/dependencies/curl-mingw/include
${PROJECT_SOURCE_DIR}/dependencies/libevent/include)


file(GLOB cppFiles 
${PROJECT_SOURCE_DIR}/src/*.cpp 
${PROJECT_SOURCE_DIR}/src/glad.c 
${PROJECT_SOURCE_DIR}/src/class/*.cpp
${PROJECT_SOURCE_DIR}/src/imgui/*.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 一定要在add_executable前面才生效
link_directories(${PROJECT_SOURCE_DIR}/dependencies/glfwbin/lib ${PROJECT_SOURCE_DIR}/dependencies/curl-mingw/lib
${PROJECT_SOURCE_DIR}/dependencies/parson ${PROJECT_SOURCE_DIR}/dependencies/libevent/lib)

add_executable(demo ${cppFiles})

target_link_libraries(demo  glfw3 curl parson event)


exec_program(xcopy ${PROJECT_SOURCE_DIR}/src/shader ${PROJECT_SOURCE_DIR}/bin)