
add_executable (Test ShiftedSortedArray.cpp)
add_test(Test Test)
include_directories(../src/)
target_link_libraries(Test gtest pthread gtest_main leet)