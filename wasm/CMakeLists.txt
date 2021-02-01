cmake_minimum_required(VERSION 3.17)
project(wasm)

set(CMAKE_CXX_STANDARD 14)
include_directories(D:\\emsdk\\emscripten\\1.38.28\\system\\include)
add_executable(wasm main.cpp)