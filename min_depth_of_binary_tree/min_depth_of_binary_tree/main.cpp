//
//  main.cpp
//  min_depth_of_binary_tree
//
//  Created by Dimash on 19.02.2023.
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

int minDepth(TreeNode* root) {
    if(!root)
        return 0;
    int lhsHeight = minDepth(root->left);
    int rhsHeight = minDepth(root->right);
    int result;
    if(min(lhsHeight, rhsHeight) == 0 and max(lhsHeight, rhsHeight) != 0)
        return max(lhsHeight, rhsHeight) + 1;
    return min(lhsHeight, rhsHeight) + 1;
}

int main(int argc, const char * argv[]) {
    TreeNode a = TreeNode(7);
    TreeNode b = TreeNode(17, NULL, &a);
    TreeNode c = TreeNode(20, &b, NULL);
    TreeNode d = TreeNode(8);
    TreeNode e = TreeNode(3, NULL, &c);
    cout<<minDepth(&e)<<endl;
    return 0;
}
