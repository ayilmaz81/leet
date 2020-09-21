#include <gtest/gtest.h>
#include "ValidNumber.hpp"

using namespace std;
TEST(ValidNumber, all)
{

    EXPECT_EQ(ValidNumber::Solve("0"),true);
    EXPECT_EQ(ValidNumber::Solve(" 0.1 "),true);
    EXPECT_EQ(ValidNumber::Solve(" 00000.1 "),true);
    EXPECT_EQ(ValidNumber::Solve(" 00000.000001 "),true);
    EXPECT_EQ(ValidNumber::Solve("abc"),false);
    EXPECT_EQ(ValidNumber::Solve("1 a"),false);
    EXPECT_EQ(ValidNumber::Solve("2e10"),true);
    EXPECT_EQ(ValidNumber::Solve(" -90e3   ") ,true);
    EXPECT_EQ(ValidNumber::Solve(" 1e"),false);
    EXPECT_EQ(ValidNumber::Solve("e3"),false);
    EXPECT_EQ(ValidNumber::Solve(" 6e-1"),true);
    EXPECT_EQ(ValidNumber::Solve(" 99e2.5 "),false);
    EXPECT_EQ(ValidNumber::Solve("53.5e93"),true);
    EXPECT_EQ(ValidNumber::Solve(" 53.5e93 "),true);
    EXPECT_EQ(ValidNumber::Solve(" 53.5e 93 "),false);
    EXPECT_EQ(ValidNumber::Solve(" 53.5 e 93 "),false);
    EXPECT_EQ(ValidNumber::Solve(" 53.5 e -93 "),false);
    EXPECT_EQ(ValidNumber::Solve(" 53.5 e-93 "),false);
    EXPECT_EQ(ValidNumber::Solve(" 53.5 e+93 "),false);
    EXPECT_EQ(ValidNumber::Solve(" 53.5 b+93 "), false);
    EXPECT_EQ(ValidNumber::Solve(" --6 "), false);
    EXPECT_EQ(ValidNumber::Solve("-+3"), false);
    EXPECT_EQ(ValidNumber::Solve("95a54e53"), false);
    EXPECT_EQ(ValidNumber::Solve("3."), true);
    EXPECT_EQ(ValidNumber::Solve(".1"), true);
    EXPECT_EQ(ValidNumber::Solve("3.2"), true);
    EXPECT_EQ(ValidNumber::Solve(".1."), false);
    EXPECT_EQ(ValidNumber::Solve("0.."), false);
    EXPECT_EQ(ValidNumber::Solve("1e."), false);
    EXPECT_EQ(ValidNumber::Solve("0e "), false);
}
