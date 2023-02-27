//
//  main.cpp
//  missing_number
//
//  Created by Dimash on 27.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

//int missingNumber(vector<int>& nums) {
//    int n = (int) nums.size();
//    int count[n+1];
//    for(int i=0; i<n+1; i++) {
//        count[i] = 0;
//    }
//    for(int i=0; i<nums.size(); i++) {
//        count[nums[i]]++;
//    }
//    for(int i=0; i<n+1; i++) {
//        if(!count[i])
//            return i;
//    }
//    return -1;
//}

//int missingNumber(vector<int>& nums) {
//    int n = (int) nums.size();
//    int sum;
//    if(n % 2) {
//        sum = n * ((n + 1) / 2);
//    } else {
//        sum = (n / 2) * (n + 1);
//    }
//    int sumOfElements = 0;
//    for(int i=0; i<nums.size(); i++)
//        sumOfElements += nums[i];
//    return sum - sumOfElements;
//}

int missingNumber(vector<int>& nums) {
    int res = (int) nums.size();
    for(int i=0; i<nums.size(); i++) {
        res ^= i;
        res ^= nums[i];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> v {3,0,1};
    cout<<missingNumber(v)<<endl;
    return 0;
}
