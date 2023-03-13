//
//  main.cpp
//  remove_nth_node_from_list
//
//  Created by Strong on 13.03.2023.
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* result = head;
    int size = 0;
    
    while (head != nullptr) {
        size++;
        head = head->next;
    }
    head = result;
    int counter = 0;
    ListNode* before;
    ListNode* after;
    if(size == n)
        return head->next;
    while (counter < ((size - n) - 1)) {
        head = head -> next;
        counter++;
    }
    before = head;
    if (head -> next)
        after = head->next->next;
    else
        after = nullptr;
    before->next = after;
    return result;
}

int main(int argc, const char * argv[]) {
    ListNode* a = new ListNode(1);
//    ListNode* b = new ListNode(2);
//    ListNode* c = new ListNode(3);
//    ListNode* d = new ListNode(4);
//    ListNode* e = new ListNode(5);
    
//    a->next = b;
//    b->next = c;
//    c->next = d;
//    d->next = e;
    
    ListNode* result = removeNthFromEnd(a, 1);
    while (result != nullptr) {
        cout<<result->val<<" ";
        result = result -> next;
    }
    
    return 0;
}
