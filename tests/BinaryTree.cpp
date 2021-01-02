#include <gtest/gtest.h>
#include "BinaryTree.hpp"
using namespace std;
TEST(BinaryTreeNode, deserialize)
{
    using type = BinaryTreeNodeInt;

    /*
           1
          / \ 
         2   3
    */
    auto root = make_shared<type>(1, make_shared<type>(2), make_shared<type>(3));
    EXPECT_EQ(*root, *deserialize<int>("1 2 3"));

    /*
           1
            \ 
             3
    */
    root = make_shared<type>(1, nullptr, make_shared<type>(3));
    EXPECT_EQ(*root, *deserialize<int>("1 null 3"));

    /*
           1
            \ 
             3
              \
               4
    */
    root = make_shared<type>(1,
                             nullptr,
                             make_shared<type>(3, nullptr, make_shared<type>(4)));
    EXPECT_EQ(*root, *deserialize<int>("1 null 3 null 4"));
    /*
           1
    */

    root = make_shared<type>(1, nullptr, nullptr);
    EXPECT_EQ(*root, *deserialize<int>("1 null null"));
    /*
          1
         / \ 
        2   3
       /   /
      4   5    
    */

    root = make_shared<type>(1,
                             make_shared<type>(2, make_shared<type>(4)),
                             make_shared<type>(3, make_shared<type>(5)));
    EXPECT_EQ(*root, *deserialize<int>("1 2 3 4 null 5"));
    /*
          1
         / \ 
        2   3
        \   /
         4 5    
    */

    root = make_shared<type>(1,
                             make_shared<type>(2, nullptr, make_shared<type>(4)),
                             make_shared<type>(3, make_shared<type>(5)));
    EXPECT_EQ(*root, *deserialize<int>("1 2 3 null 4 5"));
    /*
          1
         / \ 
        2   3
         \   \
          4   5
    */

    root = make_shared<type>(1,
                             make_shared<type>(2, nullptr, make_shared<type>(4)),
                             make_shared<type>(3, nullptr, make_shared<type>(5)));
    EXPECT_EQ(*root, *deserialize<int>("1 2 3 null 4 null 5"));

    /*
          1
         / \ 
        2   3
           / \
          4   5
    */

    root = make_shared<type>(1,
                             make_shared<type>(2),
                             make_shared<type>(3, make_shared<type>(4), make_shared<type>(5)));
    EXPECT_EQ(*root, *deserialize<int>("1 2 3 null null 4 5"));
}

TEST(BinaryTreeNode, serialize)
{
    using type = BinaryTreeNodeInt;

    /*
           1
          / \ 
         2   3
    */
    auto root = make_shared<type>(1, make_shared<type>(2), make_shared<type>(3));
    EXPECT_EQ("1 2 3", serialize<int>(root));

    /*
           1
            \ 
             3
    */
    root = make_shared<type>(1, nullptr, make_shared<type>(3));
    EXPECT_EQ("1 null 3", serialize(root));

    /*
           1
            \ 
             3
              \
               4
    */
    root = make_shared<type>(1,
                             nullptr,
                             make_shared<type>(3, nullptr, make_shared<type>(4)));
    EXPECT_EQ("1 null 3 null 4", serialize(root));
    /*
           1
    */

    root = make_shared<type>(1, nullptr, nullptr);
    EXPECT_EQ("1", serialize(root));
    /*
          1
         / \ 
        2   3
       /   /
      4   5    
    */

    root = make_shared<type>(1,
                             make_shared<type>(2, make_shared<type>(4)),
                             make_shared<type>(3, make_shared<type>(5)));
    EXPECT_EQ("1 2 3 4 null 5", serialize(root));
    /*
          1
         / \ 
        2   3
        \   /
         4 5    
    */

    root = make_shared<type>(1,
                             make_shared<type>(2, nullptr, make_shared<type>(4)),
                             make_shared<type>(3, make_shared<type>(5)));
    EXPECT_EQ("1 2 3 null 4 5", serialize(root));
    /*
          1
         / \ 
        2   3
         \   \
          4   5
    */

    root = make_shared<type>(1,
                             make_shared<type>(2, nullptr, make_shared<type>(4)),
                             make_shared<type>(3, nullptr, make_shared<type>(5)));
    EXPECT_EQ("1 2 3 null 4 null 5", serialize(root));

    /*
          1
         / \ 
        2   3
           / \
          4   5
    */

    root = make_shared<type>(1,
                             make_shared<type>(2),
                             make_shared<type>(3, make_shared<type>(4), make_shared<type>(5)));
    EXPECT_EQ("1 2 3 null null 4 5", serialize(root));
}

TEST(BinaryTreeNode, strings)
{
    string str{"test 1234 2432 null tes43 null 2352 null 23412 nulls"};
    ASSERT_EQ(serialize<string>(deserialize<string>(str)), str);
}

class BinaryTreeNodeTests : public ::testing::TestWithParam<string>
{
};

TEST_P(BinaryTreeNodeTests, integrate)
{
    auto &input = GetParam();
    ASSERT_EQ(serialize<int>(deserialize<int>(input)), input);
    ASSERT_EQ(serialize<char>(deserialize<char>(input)), input);
    ASSERT_EQ(serialize<double>(deserialize<double>(input)), input);
    ASSERT_EQ(serialize<string>(deserialize<string>(input)), input);
}

INSTANTIATE_TEST_CASE_P(
    BinaryTreeNode,
    BinaryTreeNodeTests,
    ::testing::Values("1 2 3 null null 4 5",
                      "",
                      "1",
                      "1 2",
                      "1 2 3",
                      "1 2 3 4",
                      "1 2 3 4 5",
                      "1 2 null 4 5",
                      "1 2 null null 5",
                      "1 null 3 4 5 6"));
