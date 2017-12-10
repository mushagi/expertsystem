cmake_minimum_required(VERSION 3.8)
project(expertsystem CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./../bin)
set(SOURCE_FILES ./src/main/main.cpp)
INCLUDE_DIRECTORIES(inc)

add_executable(expertsystem ${SOURCE_FILES})
target_include_directories(expertsystem PRIVATE inc)

# add the CMakeFile that defines catch

# Add an library for the example classes
add_library(expert_system_classes src/main/utils/tools.cpp
  src/main/utils/rpn.cpp) 
#############################################
#Unit tests

# enable CTest testing
enable_testing()

#Add a testing executable
add_executable(unit_tests src/test/unit_tests.cpp)
target_include_directories(unit_tests PRIVATE inc)

target_link_libraries(unit_tests expert_system_classes)
add_test(test_all ../bin/unit_tests)
