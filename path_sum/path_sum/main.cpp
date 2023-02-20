//
//  main.cpp
//  path_sum
//
//  Created by Strong on 20.02.2023.
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

bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root)
        return false;
    if(root->val) {
        targetSum -= root->val;
    }
    if(!root->left && !root->right) {
        return targetSum == 0;
    }
    bool leftHasPathSum = hasPathSum(root->left, targetSum);
    bool rightHasPathSum = hasPathSum(root->right, targetSum);
    return leftHasPathSum || rightHasPathSum;
}

int main(int argc, const char * argv[]) {
    TreeNode* a = new TreeNode(7);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(11, a, b);
    TreeNode* d = new TreeNode(4, c, nullptr);
    TreeNode* e = new TreeNode(1);
    TreeNode* f = new TreeNode(4, nullptr, e);
    TreeNode* g = new TreeNode(13);
    TreeNode* h = new TreeNode(8, g, f);
    TreeNode* root = new TreeNode(5, d, h);
    
    cout<<hasPathSum(root, 26)<<endl;
    
    return 0;
}
