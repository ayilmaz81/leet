
add_library(leet RemoveLastKthElement.cpp 
                ListNode.cpp
                DetectCycleIndirectedGraph.cpp
                CandyCrush.cpp
                RemoveDupesFromSortedLinkedList.cpp
                PalindromicLinkedList.cpp
                ReverseList.cpp
                IsBinaryTreeBST.cpp
                TrieNode.cpp
                ShiftedSortedArray.cpp)

add_executable(stdin main.cpp)

TARGET_LINK_LIBRARIES(stdin pthread leet)