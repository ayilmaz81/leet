#pragma once
#include "ListNode.hpp"
#include <map>

namespace RemoveLastKthElement{
    ListNode<int>* solve(ListNode<int>* head, int index);
    std::pair<ListNode<int>*, int> input();
    
}