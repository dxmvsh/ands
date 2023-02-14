//
//  main.cpp
//  running-sum
//
//  Created by Strong on 14.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> result(nums.size());
    result[0] = nums[0];
    for(int i=1; i<nums.size(); i++) {
        result[i] = result[i-1] + nums[i];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> n { 1,2,3,4,5 };
    vector<int> result = runningSum(n);
    for(auto x: result) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
