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
    vector<int> result;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i=0, j=0;
    while (i<nums1.size() && j<nums2.size()) {
        if(nums1[i] < nums2[j])
            i++;
        else if(nums1[i] > nums2[j])
            j++;
        else {
            result.push_back(nums1[i]);
            i++;
            j++;
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
