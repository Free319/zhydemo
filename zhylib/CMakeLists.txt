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
add_library(zhylib SHARED zhylib.cpp
${CMAKE_CURRENT_BINARY_DIR}/version.rc)
# 构建C++预定义宏
target_compile_definitions(zhylib PRIVATE "DLL_EXPORT")
# 设置动态库生成目录
set_target_properties(zhylib PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${SHARED_LIBPATH}"
  LIBRARY_OUTPUT_DIRECTORY "${STATIC_LIBPATH}"
  ARCHIVE_OUTPUT_DIRECTORY "${STATIC_LIBPATH}")

# 设置头文件搜索路径
 target_include_directories(zhylib
 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# 生成静态库
add_library(zhylib_static STATIC zhylib.cpp
${CMAKE_CURRENT_BINARY_DIR}/version.rc)
# 设置静态库生成目录
set_target_properties(zhylib_static PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${STATIC_LIBPATH}")

# 安装库和头文件
install(TARGETS zhylib zhylib_static
  EXPORT zhylibTargets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
# 安装头文件
install(FILES zhylib.h DESTINATION "include")

# 安装导出的目标
install(EXPORT zhylibTargets
  FILE zhylibTargets.cmake
  NAMESPACE zhy::
  DESTINATION lib/cmake/zhylib
)

# 生成并安装 CMake 配置文件
include(CMakePackageConfigHelpers)

# 创建版本文件
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/zhylibConfigVersion.cmake"
  VERSION ${MY_VER_PRODUCTVERSION}
  COMPATIBILITY AnyNewerVersion
)

# 创建配置文件
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/zhylibConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/zhylibConfig.cmake"
  @ONLY
)

# 安装配置文件
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/zhylibConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/zhylibConfigVersion.cmake"
  DESTINATION lib/cmake/zhylib
)
