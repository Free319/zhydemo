cmake_minimum_required(VERSION 3.28.0)
project(ZHYTEST)

include_directories(${HEADPATH})
link_directories(${LIBPATH})
link_libraries(${ZHYLIB})
set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})
add_executable(zhytest zhydemo.cpp)
