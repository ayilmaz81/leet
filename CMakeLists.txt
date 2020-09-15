cmake_minimum_required(VERSION 3.0.0)
project(leet VERSION 0.1.0)

include(CTest)
enable_testing()
add_executable(leet src/main.cpp 
                src/RemoveLastKthElement.cpp 
                src/ListNode.cpp
                src/DetectCycleIndirectedGraph.cpp
                src/CandyCrush.cpp
                src/RemoveDupesFromSortedLinkedList.cpp
                src/PalindromicLinkedList.cpp
                src/ReverseList.cpp
                src/IsBinaryTreeBST.cpp
                src/TrieNode.cpp)


TARGET_LINK_LIBRARIES(leet pthread)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
