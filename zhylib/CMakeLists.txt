cmake_minimum_required(VERSION 3.20.0)
project(ZHYLIB)

# 版本信息：
# 文件版本
set(MY_VER_FILEVERSION 1,1,0,0)
# 产品版本
set(MY_VER_PRODUCTVERSION 1.1.0.0)
# 文件描述
set(MY_VER_FILEDESCRIPTION "zhylib")
# 原始文件名
set(MY_VER_ORIGINALFILENAME "zhylib.lib")
# 文件名称
set(MY_VER_INTERNALNAME "zhy Library")
# 产品名称
set(MY_VER_PRODUCTNAME "ZHYLibrary")
# 版权
set(MY_VER_LEGALCOPYRIGHT "Copyright (C) ZHY Corporation 2024 - 2099")
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in
  ${CMAKE_CURRENT_BINARY_DIR}/version.rc
  @ONLY)

# 如果有其他头文件目录，可以添加include_directories
# include_directories(include)

# 添加动态库
set(LIBRARY_OUTPUT_PATH ${LIBPATH})
add_library(zhylib SHARED zhylib.cpp 
${CMAKE_CURRENT_BINARY_DIR}/version.rc)

# 生成静态库
add_library(zhylib_static STATIC zhylib.cpp
${CMAKE_CURRENT_BINARY_DIR}/version.rc)

# 安装
install (TARGETS zhylib
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install (TARGETS zhylib_static
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)



install (FILES zhylib.h DESTINATION "include")