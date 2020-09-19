#pragma once
#include <vector>
#include <utility>

namespace ShiftedSortedArray{
    std::pair<std::vector<int>,int> Input();

    bool Solve(const std::vector<int>& input, int target);
}