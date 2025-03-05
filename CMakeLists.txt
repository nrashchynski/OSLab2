cmake_minimum_required(VERSION 3.31.5 FATAL_ERROR)
project(OSLab2)

add_subdirectory(libs/googletest)  

enable_testing()

add_executable(main src/main.cpp src/thread_functions.cpp src/thread_data.h)

add_executable(test_findMinMax tests/test_findMinMax.cpp src/thread_functions.cpp)
target_link_libraries(test_findMinMax gtest_main)
add_test(NAME FindMinMaxTest COMMAND test_findMinMax)

add_executable(test_calculateAverage tests/test_calculateAverage.cpp src/thread_functions.cpp)
target_link_libraries(test_calculateAverage gtest_main)
add_test(NAME CalculateAverageTest COMMAND test_calculateAverage)

add_executable(test_replaceMinMax tests/test_replaceMinMax.cpp src/thread_functions.cpp)
target_link_libraries(test_replaceMinMax gtest_main)
add_test(NAME ReplaceMinMaxTest COMMAND test_replaceMinMax)