include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/dependencies/glm ${PROJECT_SOURCE_DIR}/dependencies/glfw-3.3.8.bin.WIN64/include)


file(GLOB cppFiles 
${PROJECT_SOURCE_DIR}/src/imgui/*.cpp
${PROJECT_SOURCE_DIR}/src/*.cpp 
${PROJECT_SOURCE_DIR}/src/class/*.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

add_executable(demo ${cppFiles})
link_directories(${PROJECT_SOURCE_DIR}/dependencies/glfw-3.3.8.bin.WIN64/lib-mingw-w64)

target_link_libraries(demo  glfw3)


exec_program(xcopy ${PROJECT_SOURCE_DIR}/src/shader ${PROJECT_SOURCE_DIR}/bin)