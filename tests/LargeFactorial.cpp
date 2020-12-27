#include "LargeFactorial.hpp"
#include <gtest/gtest.h>

using namespace std;

class LargeFactorialTests : public ::testing::TestWithParam<tuple<int, string>>
{
};

TEST_P(LargeFactorialTests, all)
{
    auto input = get<0>(GetParam());
    auto result = get<1>(GetParam());
    ASSERT_EQ(LargeFactorial::Solve(input), result);
}

INSTANTIATE_TEST_CASE_P(
    LargeFactorial,
    LargeFactorialTests,
    ::testing::Values(
        std::make_tuple(1, "1"),
        std::make_tuple(2, "2"),
        std::make_tuple(3, "6"),
        std::make_tuple(4, "24"),
        std::make_tuple(5, "120"),
        std::make_tuple(6, "720"),
        std::make_tuple(7, "5040"),
        std::make_tuple(8, "40320"),
        std::make_tuple(9, "362880"),
        std::make_tuple(10, "3628800"),
        std::make_tuple(11, "39916800"),
        std::make_tuple(30,"265252859812191058636308480000000")));
