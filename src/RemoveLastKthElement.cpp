#include "RemoveLastKthElement.hpp"
using namespace std;

namespace RemoveLastKthElement{
    ListNodeInt solve(ListNodeInt head, int index){
        if (head == nullptr || index == 0) return head;
        auto fast = head->next;
        auto slow = head;

        int i = 1;
        int totCount = 0;
        while(fast != nullptr && fast->next != nullptr){
            ++i;
            fast = fast->next->next;
            slow = slow->next;
        };
        if (fast == nullptr) totCount = 2*i-1;
        else if (fast->next  == nullptr) totCount = 2*i;

        if (totCount<index) return head;
        if (index == totCount) {auto node = head->next; return node;}
        auto prev = head;
        auto node = head;
        i = 0;
        while(i!= totCount - index) prev = node ,node = node->next,++i;

        prev->next = node->next;
        return head;
    }

    pair<ListNodeInt, int> input(){
        int count,index;
        cin>>count;
        vector<int> vec(count);
        auto iter = vec.begin();
        while(iter != vec.end()){
            cin>>*iter;
            ++iter;
        }
        cin>>index;
        auto head = build(vec);
        return {head,index};
    }
}