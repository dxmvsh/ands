//
//  main.cpp
//  balanced_binary_tree
//
//  Created by Dimash on 18.02.2023.
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

int height(TreeNode* root) {
    if(!root)
        return 0;
    int lhsHeight = height(root->left);
    int rhsHeight = height(root->right);
    if(lhsHeight == -1 || rhsHeight == -1)
        return -1;
    if(abs(lhsHeight - rhsHeight) > 1)
        return -1;
    return max(lhsHeight, rhsHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    if(!root)
        return true;
    int rootHeight = height(root);
    return rootHeight != -1;
}

int main(int argc, const char * argv[]) {
    TreeNode a = TreeNode(7);
    TreeNode b = TreeNode(17, NULL, &a);
    TreeNode c = TreeNode(20, &b, NULL);
    TreeNode d = TreeNode(8);
    TreeNode e = TreeNode(3, &d, &c);
    cout<<isBalanced(&e)<<endl;
    return 0;
}
