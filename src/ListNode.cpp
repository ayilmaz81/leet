#include "ListNode.hpp"

ListNodeChar build(const std::string& v){
    if (v.empty())  return nullptr;

    auto head = std::make_shared<ListNode<char>>(v.front());
    auto node = head;

    for (auto iter = std::next(std::begin(v));iter!=v.end();++iter){
        node->next = std::make_shared<ListNode<char>>(*iter);
        node = node->next;
    }

    return head;
}