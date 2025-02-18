# 项目所需cmake的最低版本
cmake_minimum_required(VERSION 3.0)
#项目的名称
project(main)

#配置编译选项 对应第2项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

#配置头文件搜索路径 对应第4项
#include_directories()
#配置库文件的搜索路径 对应第5项
#link_directories()

#设置需要编译的源文件列表
set(SRC_LIST muduo_server.cpp)

#设置可执行文件最终存储的路径 PROJECT_SOURCE_DIR是工程的根目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#把指定路径下的所有源文件名字放入变量名SRC_LIST李米娜
#aux_source_directory(. SRC_LIST)

#生成可执行文件server 由SRC_LIST变量所定义的源文件编译而来 生成库是add_lib..   对应第一项
add_executable(server ${SRC_LIST})

#表示server这个目标程序需要链接这三个库文件
target_link_libraries(server muduo_net muduo_base pthread)


