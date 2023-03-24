//
//  main.cpp
//  search_in_rotated_sorted_array
//
//  Created by Dimash on 24.03.2023.
//  
//

#include <iostream>
#include "vector"
using namespace std;

int search(vector<int>& nums, int target) {
    int n = (int) nums.size(), l = 0, r = n - 1, m = (l + r) / 2;
    while (l < r) {
        m = (l + r) / 2;
        if(nums[m] > nums[r]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    int s = l;
    l = 0;
    r = n - 1;
    if(target >= nums[s] && target <= nums[r]) {
        l = s;
    } else {
        r = s;
    }
    while (l <= r) {
        m = (l + r) / 2;
        if(target > nums[m])
            l = m + 1;
        else if(target < nums[m])
            r = m - 1;
        else
            return m;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> v = { 7,0,1,2,3,4,5,6 };
    cout<<search(v, 0)<<endl;
    return 0;
}
