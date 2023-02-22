//
//  main.cpp
//  linked_list_cycle
//
//  Created by Strong on 22.02.2023.
//

#include <iostream>
#include "vector"
#include "set"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(0);
    ListNode* d = new ListNode(-4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;
    cout<<hasCycle(a)<<endl;
    return 0;
}
