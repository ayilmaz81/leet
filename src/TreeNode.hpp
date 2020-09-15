#pragma once


template <typename T>
struct TreeNode{
    T val;
    TreeNode<T> *left = nullptr;
    TreeNode<T> *right = nullptr;
};