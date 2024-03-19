add_subdirectory(cppunit)
add_subdirectory(mylibrary)

add_executable(main main.cpp)
add_library(lib lib.cpp lib.h)
target_link_libraries(main PUBLIC lib)
target_link_libraries(lib PUBLIC mylibrary)
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}"
                                       "${PROJECT_SOURCE_DIR}/mylibrary")
target_include_directories(lib PUBLIC "${PROJECT_BINARY_DIR}"
                                          "${PROJECT_SOURCE_DIR}/mylibrary")
