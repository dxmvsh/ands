//
//  main.cpp
//  missing_number
//
//  Created by Dimash on 27.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = (int) nums.size();
    int count[n+1];
    for(int i=0; i<n+1; i++) {
        count[i] = 0;
    }
    for(int i=0; i<nums.size(); i++) {
        count[nums[i]]++;
    }
    for(int i=0; i<n+1; i++) {
        if(!count[i])
            return i;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> v {0,1};
    cout<<missingNumber(v)<<endl;
    return 0;
}
