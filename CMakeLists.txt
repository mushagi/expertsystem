cmake_minimum_required(VERSION 3.8)
project(expertsystem CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./../bin)
set(SOURCE_FILES ./src/main/main.cpp)

add_executable(expertsystem ${SOURCE_FILES})
target_include_directories(expertsystem PRIVATE include)

# add the CMakeFile that defines catch
add_subdirectory(lib/catch)


# Add an library for the example classes

#add_library(example_unit_test Reverse.cpp Palindrome.cpp )

#############################################
# Unit tests

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(unit_tests src/test/unit_tests.cpp)
target_include_directories(unit_tests PRIVATE include)

target_link_libraries(unit_tests  Catch::Test)
add_test(test_all unit_tests)
