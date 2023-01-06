cmake_minimum_required(VERSION 3.20)
project(cplusplus-learning)

set(CMAKE_CXX_STANDARD 11)
#递归遍历所有的cpp文件
file (GLOB_RECURSE files *.cpp *.c)
# 将所有的cpp文件单独生成可执行文件
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
endforeach ()
