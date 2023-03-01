//
//  main.cpp
//  add_two_numbers
//
//  Created by Dimash on 01.03.2023.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int remainder = 0;
    ListNode* result = new ListNode();
    ListNode* head = result;
    while (l1 != nullptr || l2 != nullptr) {
        int sum;
        if(!l1)
            sum = l2 -> val + remainder;
        else if(!l2)
            sum = l1 -> val + remainder;
        else
            sum = l1->val + l2->val + remainder;
        remainder = sum > 9 ? 1 : 0;
        result -> val = sum % 10;
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
        if(!l1 && !l2) {
            if (remainder != 0)
                result->next = new ListNode(remainder);
            continue;
        }
        result -> next = new ListNode();
        result = result -> next;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    ListNode* a = new ListNode(9);
    ListNode* b = new ListNode(9);
    ListNode* c = new ListNode(9);
    ListNode* d = new ListNode(9);
    ListNode* e = new ListNode(9);
    ListNode* f = new ListNode(9);
    ListNode* x = new ListNode(9);
    
    ListNode* g = new ListNode(9);
    ListNode* h = new ListNode(9);
    ListNode* j = new ListNode(9);
    ListNode* k = new ListNode(9);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = x;
    
    g->next = h;
    h->next = j;
    j->next = k;
    
    ListNode* result = addTwoNumbers(a, g);
    
    for(; result != nullptr; result=result->next)
        cout<<result->val<<" ";
    cout<<endl;
    return 0;
}
