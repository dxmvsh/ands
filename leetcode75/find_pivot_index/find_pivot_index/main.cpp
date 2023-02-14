//
//  main.cpp
//  find_pivot_index
//
//  Created by Strong on 14.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for(int i=1; i<nums.size(); i++)
        nums[i] = nums[i-1] + nums[i];
    return nums;
}

int pivotIndex(vector<int>& nums) {
    vector<int> sumOfEachIndex = runningSum(nums);
    int overallSum = sumOfEachIndex[sumOfEachIndex.size() - 1];
    if(overallSum - nums[0] == 0) {
        return 0;
    }
    for(int i=1; i<nums.size(); i++) {
        if(overallSum - sumOfEachIndex[i] == sumOfEachIndex[i-1]) {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> n {1,-1,2};
    cout<<pivotIndex(n)<<endl;
    return 0;
}
