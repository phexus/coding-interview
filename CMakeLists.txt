cmake_minimum_required(VERSION 3.8)
project(coding-interviews)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_TMP tmp)
set(SOURCE_FILES_TMP tmp tmp.cpp)
add_executable(${BUILD_TMP} ${SOURCE_FILES_TMP} tmp.cpp tmp.cpp)

set(BUILD_1 01_str_to_int)
set(SOURCE_FILES_1 01_str_to_int 01_str_to_int.cpp)
add_executable(${BUILD_1} ${SOURCE_FILES_1} 01_str_to_int.cpp)