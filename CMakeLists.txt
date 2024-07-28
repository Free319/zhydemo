cmake_minimum_required(VERSION 3.28.0)
project(ZHYDEMO)

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 定义变量
set(LIBPATH ${PROJECT_SOURCE_DIR}/lib)
# 静态库生成的路径
set(STATIC_LIBPATH ${PROJECT_SOURCE_DIR}/static)
# 动态库生成的路径
set(SHARED_LIBPATH ${PROJECT_SOURCE_DIR}/shared)
# 可执行程序的存储目录
set(EXECPATH ${PROJECT_SOURCE_DIR}/bin)
# 头文件路径
set(HEADPATH ${PROJECT_SOURCE_DIR}/zhylib)
# 库的名字
set(ZHYLIB zhylib)
# 可执行程序的名字
set(ZHYTEST zhytest)

# 给当前节点添加子目录
add_subdirectory(zhylib)

enable_testing()
add_subdirectory(zhytest)