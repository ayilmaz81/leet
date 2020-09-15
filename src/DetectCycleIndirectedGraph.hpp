#pragma once
#include <vector>
#include <utility>

namespace DetectCycleIndirectedGraph{
    using std::vector;
    using std::pair;
    pair<vector<pair<int,int>>, int>  Input();
    void Solve(vector<pair<int,int>>& graph, int vertices);
}