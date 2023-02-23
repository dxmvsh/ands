//
//  main.cpp
//  intersection_of_two_linked_lists
//
//  Created by Strong on 22.02.2023.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getNodeAfterStride(int stride, ListNode* root) {
    while (stride != 0) {
        root = root->next;
        stride--;
    }
    return root;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    for(auto a = headA; a != nullptr; a = a -> next) {
        for(auto b = headB; b != nullptr; b = b -> next) {
            if (a == b)
                return a;
        }
    }
    return nullptr;
}

int main(int argc, const char * argv[]) {
    
    ListNode* a = new ListNode(5);
    ListNode* b = new ListNode(7);
    ListNode* c = new ListNode(8);
    ListNode* d = new ListNode(9);
    
    ListNode* intersection = new ListNode(101);
    ListNode* e = new ListNode(1);
    ListNode* f = new ListNode(2);
    
    ListNode* g = new ListNode(3);
    ListNode* h = new ListNode(10);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = intersection;
    
    intersection->next = e;
    e->next = f;
    
    g->next = h;
    h->next = intersection;
    
    cout<<getIntersectionNode(a, g)->val<<endl;
    
    return 0;
}
