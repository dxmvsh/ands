//
//  main.cpp
//  permutations
//
//  Created by Dimash on 25.03.2023.
//  
//

#include <iostream>
#include "vector"
using namespace std;

void permutation(vector<int> &nums, int fixedIndex, vector<vector<int>> &result) {
    if(fixedIndex == nums.size()) {
        result.push_back(nums);
        return;
    }
    for(int i=fixedIndex; i<nums.size(); i++) {
        swap(nums[fixedIndex], nums[i]);
        permutation(nums, fixedIndex + 1, result);
        swap(nums[fixedIndex], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    permutation(nums, 0, result);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v = { 1, 2, 3 };
    vector<vector<int>> result = permute(v);
    for(vector<int> a: result) {
        for(int b: a) {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}
