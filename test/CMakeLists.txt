include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(runtests test.cpp)
target_link_libraries(runtests PUBLIC mainLib gtest gtest_main)
target_include_directories(runtests PUBLIC "${PROJECT_BINARY_DIR}" "test")

include(GoogleTest)
gtest_discover_tests(runtests)
