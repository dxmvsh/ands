//
//  main.cpp
//  maximum_subarray
//
//  Created by Dimash on 28.03.2023.
//  
//

#include <iostream>
#include "vector"
using namespace std;

int maxSubArray(vector<int>& nums) {
    int result = INT_MIN;
    int n = (int) nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    result = dp[0];
    for(int i=0; i<n; i++) {
        dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
        result = max(result, dp[i]);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v = { -2,1,-3,4,-1,2,1,-5,4 };
    cout<<maxSubArray(v)<<endl;
    return 0;
}
