//
//  main.cpp
//  intersection_of_two_arrays_ii
//
//  Created by Strong on 08.03.2023.
//

#include <iostream>
#include "vector"
#include "unordered_map"
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if(nums2.size() < nums1.size())
        intersect(nums2, nums1);
    unordered_map<int, int> counter;
    vector<int> result;
    for(int i=0; i<nums1.size(); i++) {
        counter[nums1[i]]++;
    }
    for(int i=0; i<nums2.size(); i++) {
        if(counter[nums2[i]]) {
            counter[nums2[i]]--;
            result.push_back(nums2[i]);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v {1,2,12,1};
    vector<int> c {2,12};
    vector<int> result = intersect(v, c);
    for(int a: result)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
