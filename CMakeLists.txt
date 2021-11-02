cmake_minimum_required(VERSION 3.15)
project(concurrency_prog)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread ")

#boost库所在的根目录
set(BOOST_ROOT "/usr/local/include/boost")
#添加头文件搜索路径
include_directories(/usr/local/include)
#添加库文件搜索路径
link_directories(/usr/local/lib)

add_executable(e1 e1.cpp)
add_executable(e2 e2.cpp)
add_executable(e3 e3_thread_guard.cpp)
add_executable(e4 e4_move_constructor.cpp)
add_executable(e5 e5_move_thread.cpp)
add_executable(e6 e6_thread_guard2.cpp)
add_executable(e7 e7_metux.cpp)
add_executable(e8 e8_double_check_lock.cpp)
add_executable(e9 e9_call_once.cpp)
add_executable(e10 e10_shared_mutex.cpp)