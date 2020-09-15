#include <bits/stdc++.h>
#include "RemoveLastKthElement.hpp"
#include "DetectCycleIndirectedGraph.hpp"
#include "CandyCrush.hpp"
#include "RemoveDupesFromSortedLinkedList.hpp"
#include "PalindromicLinkedList.hpp"
#include "ReverseList.hpp"
#include "IsBinaryTreeBST.hpp"
#include "TrieNode.hpp"


using namespace std;



int main(){
    
    // auto input = IsBinaryTreeBST::Input();

    // cout<<IsBinaryTreeBST::Solve(input)<<endl;


    TrieNode *root = new TrieNode;

    root->addWord("ahmet");
    root->addWord("ahmety");
    root->addWord("ahmetx");

    cout<<root->exist("ahmet")<<' '
        <<root->exist("ahmety")<<' '
        <<root->exist("ahmetx")<<' '
        <<root->exist("ahme")<<' ' 
        <<root->exist("ahmetxy")<<' ' 
        <<root->exist("ahmetb")<<'\n';

    root->removeWord("ahmet");
    
    cout<<root->exist("ahmet")<<' '
        <<root->exist("ahmety")<<' '
        <<root->exist("ahmetx")<<' '
        <<root->exist("ahme")<<' ' 
        <<root->exist("ahmetxy")<<' ' 
        <<root->exist("ahmetb")<<'\n';

    return 0;

}
