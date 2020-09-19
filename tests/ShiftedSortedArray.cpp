#include <gtest/gtest.h>
#include "ShiftedSortedArray.hpp"
using namespace std;
TEST(ShiftedSortedArray, mid)
{
    vector<int> input{10,20,30,40,1,3,4,5,6};
    EXPECT_EQ(ShiftedSortedArray::Solve(input,12) ,false);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,6) , true);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,10) , true);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,1) , true);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,0) , false);
}

TEST(ShiftedSortedArray, end)
{
    vector<int> input{10,20,30,40,1};
    EXPECT_EQ(ShiftedSortedArray::Solve(input,10) ,true);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,1) ,true);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,6) , false);
}

TEST(ShiftedSortedArray, begin)
{
    vector<int> input{1,3,4,5,6,7,8};
    EXPECT_EQ(ShiftedSortedArray::Solve(input,9) ,false);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,2) ,false);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,6) , true);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,8) , true);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,1) , true);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,0) , false);
}

TEST(ShiftedSortedArray, two)
{
    vector<int> input{1,3};
    EXPECT_EQ(ShiftedSortedArray::Solve(input,1) ,true);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,3) ,true);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,0) ,false);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,4) ,false);
}
TEST(ShiftedSortedArray, one)
{
    vector<int> input{1};
    EXPECT_EQ(ShiftedSortedArray::Solve(input,9) ,false);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,1) ,true);
}
TEST(ShiftedSortedArray, empty)
{
    vector<int> input;
    EXPECT_EQ(ShiftedSortedArray::Solve(input,0) ,false);
    EXPECT_EQ(ShiftedSortedArray::Solve(input,2) ,false);
}