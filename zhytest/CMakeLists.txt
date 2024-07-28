cmake_minimum_required(VERSION 3.20.0)
project(ZHYTEST)

include_directories(${HEADPATH})
link_directories(${LIBPATH})
link_libraries(${ZHYLIB})
#set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})
add_executable(zhytest zhydemo.cpp)

# 安装
install (TARGETS zhytest
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

# 启用测试
#add_test(NAME zhytest COMMAND zhytest)
add_test(demo_test zhytest 2 3 4 5)

# 测试程序是否成功运行
#add_test (test_run zhytest 5 2)
#set_tests_properties (test_run
#  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")
#
## 测试帮助信息是否可以正常提示
#add_test (test_usage zhytest)
#set_tests_properties (test_usage
#  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")
#
## 定义一个宏，用来简化测试工作
#macro (do_test arg1 arg2 result)
#  add_test (test_${arg1}_${arg2} zhytest ${arg1} ${arg2})
#  set_tests_properties (test_${arg1}_${arg2}
#    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
#endmacro (do_test)
#
## 利用 do_test 宏，测试一系列数据
#do_test (5 2 "is 25")
#do_test (10 5 "is 100000")
#do_test (2 10 "is 1024")
