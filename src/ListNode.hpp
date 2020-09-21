
#pragma once
#include <iostream>
#include <vector>
#include <memory>

template<typename T>
struct ListNode{
    explicit ListNode(T v):val(v){}
    T val;
    std::shared_ptr<ListNode<T>> next ;
};
template<typename T>
std::shared_ptr<ListNode<T>> build(const std::vector<T>& v){
    if (v.empty())  return nullptr;

    auto head = std::make_shared<ListNode<T>>(v.front());
    auto node = head;

    for (auto iter = std::next(std::begin(v));iter!=v.end();++iter){
        node->next = std::make_shared<ListNode<T>>(*iter);
        node = node->next;
    }

    return head;
}

template<typename T>
std::vector<T> to_vector(std::shared_ptr<ListNode<T>> head){
    std::vector<T> ret;
    while(head != nullptr){
        ret.push_back(head->val);
        head = head->next;
    }

    return ret;
}

using ListNodeChar = std::shared_ptr<ListNode<char>>; 
using ListNodeInt =  std::shared_ptr<ListNode<int>>;

ListNodeChar build(const std::string& v);

template<typename T>
void print(const std::shared_ptr<ListNode<T>> head){
    while(head != nullptr){std::cout<<head->val<< " ";head = head.next;}
    std::cout<<'\n';
}