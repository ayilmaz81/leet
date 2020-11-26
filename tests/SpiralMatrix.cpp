#include <gtest/gtest.h>
#include "SpiralMatrix.hpp"

using namespace std;
TEST(SpiralMatrix, all)
{
    std::vector<std::vector<int>> ans0;
    EXPECT_EQ(SpiralMatrix::Solve(0),ans0);

    std::vector<std::vector<int>> ans1 = {{1}};
    EXPECT_EQ(SpiralMatrix::Solve(1),ans1);

    std::vector<std::vector<int>> ans2 = {  {1,2},
                                            {4,3}};
    EXPECT_EQ(SpiralMatrix::Solve(2),ans2);

    std::vector<std::vector<int>> ans3 = {  {1,2,3},
                                            {8,9,4},
                                            {7,6,5}};
    EXPECT_EQ(SpiralMatrix::Solve(3),ans3);

    std::vector<std::vector<int>> ans4 = {  {1, 2, 3, 4},
                                            {12,13,14,5},
                                            {11,16,15,6},
                                            {10,9, 8, 7}};
    EXPECT_EQ(SpiralMatrix::Solve(4),ans4);

    std::vector<std::vector<int>> ans5 = {  {1,  2,  3,  4,  5},
                                            {16, 17, 18, 19, 6},
                                            {15, 24, 25, 20, 7},
                                            {14, 23, 22, 21, 8},
                                            {13, 12, 11, 10, 9}};
    EXPECT_EQ(SpiralMatrix::Solve(5),ans5);

}

