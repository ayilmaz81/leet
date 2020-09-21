#include <gtest/gtest.h>
#include "ReorderList.hpp"

using namespace std;


class ReorderListTests :public ::testing::TestWithParam<std::pair<vector<int>, vector<int>>> {};

TEST_P(ReorderListTests, all) {
    ListNodeInt node = build<int>(GetParam().first);
    ReorderList::Solve(node);
    auto ans = to_vector(node);
    ASSERT_EQ(ans,GetParam().second);
}

INSTANTIATE_TEST_CASE_P(
        ReorderList,
        ReorderListTests,
        ::testing::Values(
                std::make_pair(vector<int>{1,2,3,4,5,6,7}, vector<int>{1,7,2,6,3,5,4}),
                std::make_pair(vector<int>{1,2,3,4,5,6}, vector<int>{1,6,2,5,3,4}),
                std::make_pair(vector<int>{1,2,3,4,5}, vector<int>{1,5,2,4,3}),
                std::make_pair(vector<int>{1,2,3,4}, vector<int>{1,4,2,3}),
                std::make_pair(vector<int>{1,2,3}, vector<int>{1,3,2}),
                std::make_pair(vector<int>{1,2}, vector<int>{1,2}),
                std::make_pair(vector<int>{1}, vector<int>{1}),
                std::make_pair(vector<int>{}, vector<int>{})));
