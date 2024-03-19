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

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(runtests test.cpp)
target_link_libraries(runtests PUBLIC mainLib gtest gtest_main)
target_include_directories(runtests PUBLIC "${PROJECT_BINARY_DIR}")

include(GoogleTest)
gtest_discover_tests(runtests)
