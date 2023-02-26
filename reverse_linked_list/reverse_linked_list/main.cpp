//
//  main.cpp
//  reverse_linked_list
//
//  Created by Dimash on 26.02.2023.
//

#include <iostream>
#include "stack"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if(!head)
        return nullptr;
    stack<ListNode*> nodeStack;
    for(auto node = head; node != nullptr; node = node->next)
        nodeStack.push(node);
    ListNode* newHead = nodeStack.top();
    ListNode* result = nodeStack.top();
    nodeStack.pop();
    while (!nodeStack.empty()) {
        newHead->next = nodeStack.top();
        nodeStack.pop();
        newHead = newHead->next;
    }
    if(newHead->next)
        newHead->next = nullptr;
    return result;
}

int main(int argc, const char * argv[]) {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    
    ListNode* result = reverseList(nullptr);
    for(auto node = result; node != nullptr; node=node->next)
        cout<<node->val<<" ";
    cout<<endl;
    return 0;
}
