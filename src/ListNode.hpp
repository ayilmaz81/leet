
#pragma once
#include <iostream>
#include <vector>

template<typename T>
struct ListNode{
    T val;
    ListNode<T>* next;
};
template<typename T>
ListNode<T>* build(const std::vector<T>& v){
    if (v.empty())  return nullptr;

    auto * head = new ListNode<T>{v.front()};
    auto node = head;

    for (auto iter = std::next(std::begin(v));iter!=v.end();++iter){
        node->next = new ListNode<T>{*iter};
        node = node->next;
    }

    return head;
}
using ListNodeChar = ListNode<char>; 
ListNodeChar* build(const std::string& v);

template<typename T>
void print(const ListNode<T>* head){
    while(head != nullptr){std::cout<<head->val<< " ";head = head->next;}
    std::cout<<'\n';
}