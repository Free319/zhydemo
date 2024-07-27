cmake_minimum_required(VERSION 3.28.0)

project(ZHYLIB)
set(LIBRARY_OUTPUT_PATH ${LIBPATH})
# 添加静态库
add_library(zhylib STATIC zhylib.cpp)

# 如果有其他头文件目录，可以添加include_directories
# include_directories(include)

install (TARGETS zhylib
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install (FILES zhylib.h DESTINATION "include")