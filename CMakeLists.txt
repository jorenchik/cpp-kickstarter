cmake_minimum_required(VERSION 3.1...3.28)
enable_testing()
project(
  Template
  VERSION 0.1.0
  LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(src)
add_subdirectory(test)
