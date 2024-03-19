add_subdirectory(Cppunit)
add_subdirectory(MyLibrary)

add_executable(main main.cpp)
add_library(mainLib main_lib.cpp main_lib.h)
target_link_libraries(main PUBLIC mainLib)
target_link_libraries(mainLib PUBLIC mylibrary)
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}"
                                       "${PROJECT_SOURCE_DIR}/MyLibrary")
target_include_directories(mainLib PUBLIC "${PROJECT_BINARY_DIR}"
                                          "${PROJECT_SOURCE_DIR}/MyLibrary")
