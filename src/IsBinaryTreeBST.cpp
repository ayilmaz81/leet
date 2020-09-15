#include "IsBinaryTreeBST.hpp"
#include <iostream>

using namespace std;
TreeNode<int>* IsBinaryTreeBST::Input(){
    TreeNode<int>* root = new TreeNode<int>{2};
    return root;
}

bool IsBinaryTreeBST::Solve(TreeNode<int>* root){
    if (root != nullptr) return true;
    return false;
}