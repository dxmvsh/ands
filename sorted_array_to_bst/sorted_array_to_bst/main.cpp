//
//  main.cpp
//  sorted_array_to_bst
//
//  Created by Dimash on 17.02.2023.
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

vector<int> slice(vector<int> nums, int begin, int end) {
    vector<int> result;
    for(int i=begin; i<end; i++)
        result.push_back(nums[i]);
    return result;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int count = (int) nums.size();
    if (!count) {
        return NULL;
    }
    int currentValue = nums[count / 2];
    if(count == 1) {
        TreeNode* root = new TreeNode(currentValue);
        return root;
    }
    vector<int> left = slice(nums, 0, count / 2);
    vector<int> right = slice(nums, (count / 2) + 1, count);
    TreeNode* leftNode = sortedArrayToBST(left);
    TreeNode* rightNode = sortedArrayToBST(right);
    TreeNode* root = new TreeNode(currentValue, leftNode, rightNode);
    return root;
}

void printBST(TreeNode* root) {
    if(!root) {
        return;
    }
    if(root->left != NULL)
        printBST(root->left);
    cout<<root->val<<" ";
    if(root->right != NULL)
        printBST(root->right);
}

int main(int argc, const char * argv[]) {
    vector<int> nums {-10, -3, 0, 5, 9};
    TreeNode* result = sortedArrayToBST(nums);
    printBST(result);
    return 0;
}
