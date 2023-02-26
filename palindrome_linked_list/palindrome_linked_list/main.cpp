//
//  main.cpp
//  palindrome_linked_list
//
//  Created by Dimash on 26.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    vector<int> v;
    for(auto node = head; node != nullptr; node = node->next)
        v.push_back(node->val);
    for(int i=0; i<(v.size() / 2); i++) {
        if(v[i] != v[v.size() - i - 1])
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(2);
    ListNode* d = new ListNode(1);
    a->next = b;
    b->next = c;
    c->next = d;
    cout<<isPalindrome(a)<<endl;
    return 0;
}
