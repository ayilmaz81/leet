#include "ReverseList.hpp"
#include <string>

using namespace std;

ListNodeChar ReverseList::Input(){
    string inp;

    cin>>inp;

    return build(inp);
}


// A->B->C->D => A<-B<-C<-D
// NEXT = C->next;
// C->next = B (PREV)
// prev = C
// NODE = NEXT;

ListNodeChar ReverseList::Solve(ListNodeChar head){

    if (head == nullptr || head->next == nullptr) return head;

    auto node = head;
    ListNodeChar prev = nullptr;

    while(node!=nullptr){
        auto next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}