//
//  main.cpp
//  symmetric_tree
//
//  Created by Dimash on 14.02.2023.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* lhs, TreeNode* rhs) {
    if(!lhs && !rhs) {
        return true;
    }
    if(!lhs || !rhs) {
        return false;
    }
    if(lhs->val != rhs->val)
        return false;
    if(!lhs->left && !rhs->right && !lhs->right && !rhs->right)
        return lhs->val == rhs->val;
    bool firstHalfEqual = isSymmetric(lhs->left, rhs->right);
    bool secondHalfEqual = isSymmetric(lhs->right, rhs->left);
    return firstHalfEqual && secondHalfEqual;
}

bool isSymmetric(TreeNode* root) {
    if(!root->left && !root->right)
        return true;
    if(!root->left || !root->right)
        return false;
    return isSymmetric(root->left, root->right);
}

int main(int argc, const char * argv[]) {
    TreeNode a = TreeNode(-7);
    TreeNode b = TreeNode(47, &a, NULL);
    TreeNode c = TreeNode(97, NULL, &b);
    TreeNode d = TreeNode(-7);
    TreeNode e = TreeNode(80, NULL, &d);
    TreeNode f = TreeNode(97, &e, NULL);
    TreeNode root = TreeNode(2, &c, &f);
    cout<<isSymmetric(&root)<<endl;
    return 0;
}
