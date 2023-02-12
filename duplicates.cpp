#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;
    int value;
    while(current != NULL) {
        value = current->val;
        if(current->next != NULL && current->next->val == value) {
            ListNode* temp = current->next;
            while(temp != NULL && temp->val == value) {
                temp = temp->next;
            }
            current->next = temp;
        }
        current = current->next;
    };
    return head;
}

void printValues(ListNode* head) {
    while (head != NULL) {
        cout<<head->val<<" ";
        head = head->next;
    }
}

int main() {
    ListNode x = ListNode(1);
    ListNode y = ListNode(1);
    ListNode z = ListNode(2);
    ListNode a = ListNode(2);
    ListNode b = ListNode(2);
    ListNode c = ListNode(3);
    ListNode d = ListNode(3);
    x.next = &y;
    y.next = &z;
    z.next = &a;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    printValues(&x);
    cout<<endl;
    deleteDuplicates(&x);
    printValues(&x);
    return 0;
}
