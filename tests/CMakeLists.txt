
add_executable (Test ShiftedSortedArray.cpp
                    SimpleCalculator.cpp
                    ValidNumber.cpp
                    ReorderList.cpp
                    FibonacciSum.cpp
                    SpiralMatrix.cpp
                    RotateArray.cpp
                    IntervalMap.cpp
                    MaximumAvarageSubarray.cpp
                    PalindromePartitioning.cpp
                    DecodedStringIndex.cpp
                    LargeFactorial.cpp
                    BinaryTree.cpp)
add_test(Test Test)
include_directories(../src/)
target_link_libraries(Test gtest pthread gtest_main leet)