cmake_minimum_required(VERSION 3.1...3.28)
project(
  Template
  VERSION 0.1.0
  LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(Munit)
add_subdirectory(MyLibrary)

add_executable(main main.c)
add_library(mainLib main_lib.c main_lib.h)
target_link_libraries(main PUBLIC mainLib)
target_link_libraries(mainLib PUBLIC mylibrary)
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}"
                                       "${PROJECT_SOURCE_DIR}/MyLibrary")
target_include_directories(mainLib PUBLIC "${PROJECT_BINARY_DIR}"
                                          "${PROJECT_SOURCE_DIR}/MyLibrary")

add_executable(test test.c)
target_link_libraries(test PUBLIC munit)
target_link_libraries(test PUBLIC mainLib)
target_include_directories(test PUBLIC "${PROJECT_BINARY_DIR}"
                                       "${PROJECT_SOURCE_DIR}/Munit")
