//
//  main.cpp
//  single_number
//
//  Created by Strong on 21.02.2023.
//

#include <iostream>
#include "vector"
#include "set"
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = nums[0];
    for(int i=1; i<nums.size(); i++)
        result = result ^ nums[i];
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{ 4,1,2,1,2 };
    cout<<singleNumber(nums)<<endl;
    return 0;
}
