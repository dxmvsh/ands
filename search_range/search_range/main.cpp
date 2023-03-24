//
//  main.cpp
//  search_range
//
//  Created by Dimash on 24.03.2023.
//  
//

#include <iostream>
#include "vector"
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    int n = (int) nums.size(), l = 0, r = n - 1;
    int leftmostIndex = -1, rightmostIndex = -1;
    bool didFindTarget = false;
    while (l<=r) {
        int m = (l + r) / 2;
        if(didFindTarget) {
            if(l >= 0 && target == nums[l]) {
                l--;
                continue;
            } else {
                leftmostIndex = l + 1;
                l++;
                break;
            }
        }
        if(target > nums[m]) {
            l = m + 1;
        } else if (target < nums[m]) {
            r = m - 1;
        } else {
            didFindTarget = true;
            l = m;
            l--;
        }
    }
    if(!didFindTarget) {
        result.push_back(leftmostIndex);
        result.push_back(rightmostIndex);
        return result;
    }
    r = n - 1;
    didFindTarget = false;
    while (l<=r) {
        if(didFindTarget) {
            if(r < n && target == nums[r]) {
                r++;
                continue;
            } else {
                rightmostIndex = r - 1;
                break;
            }
        }
        int m = (l + r) / 2;
        if(target > nums[m]) {
            l = m + 1;
        } else if (target < nums[m]) {
            r = m - 1;
        } else {
            didFindTarget = true;
            r = m;
            r++;
        }
    }
    result.push_back(leftmostIndex);
    result.push_back(rightmostIndex);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v = { 10 };
    vector<int> result = searchRange(v, 10);
    for(int a: result)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
