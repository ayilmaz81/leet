#include <gtest/gtest.h>
#include <algorithm>
#include <tuple>

#include "RotateArray.hpp"

using namespace std;

class RotateArrayTests :public ::testing::TestWithParam< tuple<vector<int>, int, vector<int>> > {};

TEST_P(RotateArrayTests, all) {
    auto input = get<0>(GetParam());
    auto k = get<1>(GetParam());
    RotateArray::Solve(input,k);
    ASSERT_EQ(input, get<2>(GetParam()));
}

INSTANTIATE_TEST_CASE_P(
        RotateArray,
        RotateArrayTests,
        ::testing::Values(
                std::make_tuple(vector<int>{1,2,3,4,5,6,7}, 0, vector<int>{1,2,3,4,5,6,7}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7}, 1, vector<int>{7,1,2,3,4,5,6}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7}, 2, vector<int>{6,7,1,2,3,4,5}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7}, 3, vector<int>{5,6,7,1,2,3,4}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7}, 4, vector<int>{4,5,6,7,1,2,3}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7}, 5, vector<int>{3,4,5,6,7,1,2}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7}, 6, vector<int>{2,3,4,5,6,7,1}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7}, 7, vector<int>{1,2,3,4,5,6,7}),
                std::make_tuple(vector<int>{}, 10 ,vector<int>{})));

INSTANTIATE_TEST_CASE_P(
        RotateArray2,
        RotateArrayTests,
        ::testing::Values(
                std::make_tuple(vector<int>{1,2,3,4,5,6,7,8}, 0, vector<int>{1,2,3,4,5,6,7,8}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7,8}, 1, vector<int>{8,1,2,3,4,5,6,7}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7,8}, 2, vector<int>{7,8,1,2,3,4,5,6}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7,8}, 3, vector<int>{6,7,8,1,2,3,4,5}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7,8}, 4, vector<int>{5,6,7,8,1,2,3,4}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7,8}, 5, vector<int>{4,5,6,7,8,1,2,3}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7,8}, 6, vector<int>{3,4,5,6,7,8,1,2}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7,8}, 7, vector<int>{2,3,4,5,6,7,8,1}),
                std::make_tuple(vector<int>{1,2,3,4,5,6,7,8}, 8, vector<int>{1,2,3,4,5,6,7,8}),
                std::make_tuple(vector<int>{}, 10 ,vector<int>{})));
