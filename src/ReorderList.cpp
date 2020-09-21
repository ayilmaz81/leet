#include "ReorderList.hpp"
#include <iostream>
using namespace std;
ListNodeInt* ReorderList::Input(){
    int k;
    cin>>k;
    vector<int> vec(k);
    while(k--){
        cin>>vec[k];
    }
    return build(vec);
}
namespace{
    template<typename T>
    ListNode<T>* ReverseList(ListNode<T> *head){
        auto node = head;
        ListNode<T>* prev = nullptr;
        while(node != nullptr){
            auto next = node->next;
            node->next = prev;

            prev = node;
            node = next;
        }

        return prev;
    }
}
void ReorderList::Solve(ListNodeInt* head){
    if (head == nullptr || head->next == nullptr)  return;
    auto fast = head;
    auto slow = head;
    auto prev = head;
    do{
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }while(fast != nullptr && fast->next != nullptr &&  slow !=  nullptr);
    prev->next = nullptr;
    auto rev = ReverseList<int>(slow);
    
    auto node = head;

    while(node != nullptr && rev != nullptr){
        auto nextnode = node->next;
        auto nextrev = rev->next;

        node->next = rev;
        if(nextnode) rev->next = nextnode;
        node = nextnode;
        rev = nextrev;
    }
    return;
}