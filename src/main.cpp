#include "RemoveLastKthElement.hpp"
#include "DetectCycleIndirectedGraph.hpp"
#include "CandyCrush.hpp"
#include "RemoveDupesFromSortedLinkedList.hpp"
#include "PalindromicLinkedList.hpp"
#include "ReverseList.hpp"
#include "IsBinaryTreeBST.hpp"
#include "TrieNode.hpp"
#include "ShiftedSortedArray.hpp"

using namespace std;



int main(){
    
    auto input = ShiftedSortedArray::Input();
    cout<<ShiftedSortedArray::Solve(input.first, input.second)<<'\n';

    return 0;

}
