//
//  main.cpp
//  sametree
//
//  Created by Strong on 14.02.2023.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* lhs, TreeNode* rhs) {
    if(lhs == NULL and rhs == NULL) {
        return true;
    }
    if(lhs == NULL || rhs == NULL) {
        return false;
    }
    if(lhs->val != rhs->val) {
        return false;
    }
    bool leftSideIsSame = isSameTree(lhs->left, rhs->left);
    bool rightSideIsSame = isSameTree(lhs->right, rhs->right);
    return leftSideIsSame && rightSideIsSame;
}

int main(int argc, const char * argv[]) {
    TreeNode lhs3 = TreeNode(3);
    TreeNode rhs3 = TreeNode(3);
    TreeNode lhs2 = TreeNode(4, NULL, &lhs3);
    TreeNode rhs2 = TreeNode(2, NULL, &rhs3);
    TreeNode lhs1 = TreeNode(2, &lhs2, NULL);
    TreeNode rhs1 = TreeNode(4, &rhs2, NULL);
    TreeNode leftOrigin = TreeNode(1, NULL, &lhs1);
    TreeNode rightOrigin = TreeNode(1, NULL, &rhs1);
//    TreeNode a = TreeNode(2);
//    TreeNode b = TreeNode(3);
//    TreeNode e = TreeNode(5);
//    TreeNode d = TreeNode(4);
//    TreeNode c = TreeNode(3, &d, &e);
//    TreeNode leftOrigin = TreeNode(1, &a, &b);
//    TreeNode rightOrigin = TreeNode(1, &a, &c);
    cout<<isSameTree(&leftOrigin, &rightOrigin)<<endl;
    
    return 0;
}
