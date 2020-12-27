#include <gtest/gtest.h>
#include "DecodedStringIndex.hpp"

using namespace std;

class DecodedStringIndexTests : public ::testing::TestWithParam<tuple<string, string>>
{
};

TEST_P(DecodedStringIndexTests, small)
{
    auto input = get<0>(GetParam());
    auto result = get<1>(GetParam());
    for (size_t i = 0; i < result.size(); ++i)
    {
        ASSERT_EQ(DecodedStringIndex::Solve(input, i + 1), result[i]);
    }
}

INSTANTIATE_TEST_CASE_P(
    DecodedStringIndex,
    DecodedStringIndexTests,
    ::testing::Values(
        std::make_tuple("abc2defg3", "abcabcdefgabcabcdefgabcabcdefg"),
        std::make_tuple("abc2defg", "abcabcdefg"),
        std::make_tuple("av", "av"),
        std::make_tuple("a2", "aa"),
        std::make_tuple("a2b3", "aabaabaab")));

TEST(DecodedStringIndex, mixed)
{
    EXPECT_EQ(DecodedStringIndex::Solve("vzpp636m8y", 2920), 'z');
    EXPECT_EQ(DecodedStringIndex::Solve("ha22", 5), 'h');
    EXPECT_EQ(DecodedStringIndex::Solve("a2345678999999999999999", 1), 'a');
    EXPECT_EQ(DecodedStringIndex::Solve("y959q969u3hb22odq595", 222280369), 'y');
    EXPECT_EQ(DecodedStringIndex::Solve("czjkk9elaqwiz7s6kgvl4gjixan3ky7jfdg3kyop3husw3fm289thisef8blt7a7zr5v5lhxqpntenvxnmlq7l34ay3jaayikjps", 768077956), 'c');
}