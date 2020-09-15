#include "ListNode.hpp"

ListNode<char>* build(const std::string& v){
    if (v.empty())  return nullptr;

    auto * head = new ListNode<char>{v.front()};
    auto node = head;

    for (auto iter = std::next(std::begin(v));iter!=v.end();++iter){
        node->next = new ListNode<char>{*iter};
        node = node->next;
    }

    return head;
}
// ListNode* build(const std::vector<int>&v){
//     if (v.empty())  return nullptr;

//     ListNode * head = new ListNode{v.front()};
//     auto node = head;

//     for (auto iter = std::next(std::begin(v));iter!=v.end();++iter){
//         node->next = new ListNode{*iter};
//         node = node->next;
//     }

//     return head;

// }

// void print(const ListNode* head){
//     while(head != nullptr){std::cout<<head->val<< " ";head = head->next;}

//     std::cout<<'\n';
// }
