
add_library(leet RemoveLastKthElement.cpp 
                ListNode.cpp
                DetectCycleIndirectedGraph.cpp
                CandyCrush.cpp
                RemoveDupesFromSortedLinkedList.cpp
                PalindromicLinkedList.cpp
                ReverseList.cpp
                IsBinaryTreeBST.cpp
                TrieNode.cpp
                ShiftedSortedArray.cpp
                SimpleCalculator.cpp
                ValidNumber.cpp
                ReorderList.cpp
                ListNode.cpp
                FibonacciSum.cpp
                SpiralMatrix.cpp
                RotateArray.cpp
                MaximumAvarageSubarray.cpp
                PalindromePartitioning.cpp
                DecodedStringIndex.cpp
                LargeFactorial.cpp)

add_executable(stdin main.cpp)

target_compile_options(leet PRIVATE -Werror -Wall -Wextra)

TARGET_LINK_LIBRARIES(stdin pthread leet)