#include <gtest/gtest.h>
#include "PalindromePartitioning.hpp"

using namespace std;
TEST(PalindromePartitioning, all)
{
    EXPECT_EQ(PalindromePartitioning::Solve("aa"), (vector<vector<string>>{{"a", "a"}, {"aa"}}));
    EXPECT_EQ(PalindromePartitioning::Solve("aba"), (vector<vector<string>>{{"a", "b", "a"}, {"aba"}}));
    EXPECT_EQ(PalindromePartitioning::Solve("aaa"), (vector<vector<string>>{{"a", "a", "a"}, {"a", "aa"}, {"aa", "a"}, {"aaa"}}));
    EXPECT_EQ(PalindromePartitioning::Solve("aab"), (vector<vector<string>>{{"a", "a", "b"}, {"aa", "b"}}));
    EXPECT_EQ(PalindromePartitioning::Solve("bbbcc"), (vector<vector<string>>{{"b", "b", "b", "c", "c"}, {"b", "b", "b", "cc"}, {"b", "bb", "c", "c"}, {"b", "bb", "cc"}, {"bb", "b", "c", "c"}, {"bb", "b", "cc"}, {"bbb", "c", "c"}, {"bbb", "cc"}}));
}