#include <gtest/gtest.h>
#include "FibonacciSum.hpp"

using namespace std;
TEST(FibonacciSum, all)
{
    EXPECT_EQ(FibonacciSum::Solve(1) , 1);
    EXPECT_EQ(FibonacciSum::Solve(2) , 1);
    EXPECT_EQ(FibonacciSum::Solve(3) , 1);
    EXPECT_EQ(FibonacciSum::Solve(4) , 1);
    EXPECT_EQ(FibonacciSum::Solve(5) , 1);
    EXPECT_EQ(FibonacciSum::Solve(10) ,1);
    EXPECT_EQ(FibonacciSum::Solve(1000) , 3);
    EXPECT_EQ(FibonacciSum::Solve(90000) , 3);
    EXPECT_EQ(FibonacciSum::Solve(1000000) , 4);
}