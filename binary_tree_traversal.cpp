//
//  main.cpp
//  binary_tree_inorder_traversal
//
//  Created by Strong on 14.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> merge(vector<int> a, vector<int> b) {
    for(auto x: b) {
        a.push_back(x);
    }
    return a;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if(!root) {
        return result;
    }
    if(root->left) {
        result = merge(result, inorderTraversal(root->left));
    }
    result.push_back(root->val);
    if(root->right) {
        result = merge(result, inorderTraversal(root->right));
    }
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode a = TreeNode(3);
    TreeNode b = TreeNode(2, &a, NULL);
    TreeNode c = TreeNode(1, NULL, &b);
    vector<int> result = inorderTraversal(&c);
    for(auto x: result) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
