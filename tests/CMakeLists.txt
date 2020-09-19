
add_executable (Test ShiftedSortedArray.cpp)
include_directories(../src/)
target_link_libraries(Test gtest pthread gtest_main leet)