#include "PalindromicLinkedList.hpp"
#include "ReverseList.hpp"
#include <string>

using namespace std;

ListNodeChar PalindromicLinkedList::Input(){
    string input;
    cin>>input;
    return build(input);
}

ListNodeChar reverseList(ListNodeChar head){
    return ReverseList::Solve(head);
}

bool PalindromicLinkedList::Solve(ListNodeChar head){
    auto slow = head;
    auto fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = reverseList(slow);
    auto node = head;
    while(node != nullptr && slow != nullptr ){
        if (node->val != slow->val) return false;
        node = node->next;
        slow = slow->next;

    }
    return true;
}