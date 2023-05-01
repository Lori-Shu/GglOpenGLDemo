include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/dependencies/glfw-3.3.8.bin.WIN64/include 
${PROJECT_SOURCE_DIR}/dependencies/ffmpeg-master-latest-win64-gpl-shared/include)

file(GLOB cppFiles 
${PROJECT_SOURCE_DIR}/src/glad.c 
${PROJECT_SOURCE_DIR}/src/*.cpp 
${PROJECT_SOURCE_DIR}/src/class/*.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

link_directories(${PROJECT_SOURCE_DIR}/dependencies/glfw-3.3.8.bin.WIN64/lib-mingw-w64 ${PROJECT_SOURCE_DIR}/dependencies/ffmpeg-master-latest-win64-gpl-shared/lib)

add_executable(demo ${cppFiles})

target_link_libraries(demo glfw3 avcodec.dll avdevice.dll avfilter.dll avutil.dll avformat.dll postproc.dll swresample.dll swscale.dll)

exec_program(xcopy ARGS ${PROJECT_SOURCE_DIR}/src/shader ${PROJECT_SOURCE_DIR}/bin)