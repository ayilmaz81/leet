
add_executable (Test ShiftedSortedArray.cpp
                    SimpleCalculator.cpp
                    ValidNumber.cpp
                    ReorderList.cpp
                    FibonacciSum.cpp)
add_test(Test Test)
include_directories(../src/)
target_link_libraries(Test gtest pthread gtest_main leet)