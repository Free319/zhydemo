cmake_minimum_required(VERSION 3.20.0)
project(ZHYMYLIB)

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
add_library(zhylib SHARED zhylib.cpp 
${CMAKE_CURRENT_BINARY_DIR}/version.rc)
# 构建C++预定义宏
target_compile_definitions(zhylib PRIVATE "DLL_EXPORT")
# 设置动态库生成目录
set_target_properties(zhylib PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${SHARED_LIBPATH}"
  LIBRARY_OUTPUT_DIRECTORY "${STATIC_LIBPATH}"
  ARCHIVE_OUTPUT_DIRECTORY "${STATIC_LIBPATH}")

# 生成静态库
add_library(zhylib_static STATIC zhylib.cpp
${CMAKE_CURRENT_BINARY_DIR}/version.rc)
# 设置静态库生成目录
set_target_properties(zhylib_static PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${STATIC_LIBPATH}")

# 安装
install (TARGETS zhylib
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install (TARGETS zhylib_static
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

# 安装头文件
install (FILES zhylib.h DESTINATION "include")