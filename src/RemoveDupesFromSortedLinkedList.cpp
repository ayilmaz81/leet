
#include "RemoveDupesFromSortedLinkedList.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ListNodeInt RemoveDupesFromSortedLinkedList::Input(){
    int k;
    cin>>k;
    vector<int> inp(k);
    while(k--){
        cin>>inp[k];
    }
    sort(begin(inp),end(inp));

    return build(inp);
}

ListNodeInt RemoveDupesFromSortedLinkedList::Solve(ListNodeInt head){
    auto prev = head;
    auto node = head->next;
    while(node != nullptr){
        if(node->val == prev->val){
            while(node != nullptr && prev->val == node->val){
                auto n = node->next;
                node = n;
            }
            prev->next = node;
            if (node == nullptr) break;
        }
        prev = node;
        node = node->next;

    }
    return head;
}