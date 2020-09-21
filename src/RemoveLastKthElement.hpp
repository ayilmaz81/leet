#pragma once
#include "ListNode.hpp"
#include <utility>

namespace RemoveLastKthElement{
    ListNodeInt solve(ListNodeInt head, int index);
    std::pair<ListNodeInt, int> input();
    
}