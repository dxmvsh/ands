//
//  main.cpp
//  max_depth_binary_tree
//
//  Created by Dimash on 16.02.2023.
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

int maxDepthCount = -1;

void depth(TreeNode* root, int currentCount) {
    if(currentCount > maxDepthCount) {
        maxDepthCount = currentCount;
    }
    if(!root) {
        return;
    }
    depth(root->left, currentCount + 1);
    depth(root->right, currentCount + 1);
}

int maxDepth(TreeNode* root) {
    depth(root, 0);
    return maxDepthCount;
}

int main(int argc, const char * argv[]) {
    TreeNode left2 = TreeNode(15);
    TreeNode right2 = TreeNode(7);
    TreeNode left1 = TreeNode(1, &left2, &right2);
    TreeNode right1 = TreeNode(1);
    TreeNode root = TreeNode(3, &left1, &right1);
    cout<<maxDepth(&root)<<endl;
    return 0;
}
