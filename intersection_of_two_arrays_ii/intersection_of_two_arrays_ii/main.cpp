//
//  main.cpp
//  intersection_of_two_arrays_ii
//
//  Created by Strong on 08.03.2023.
//

#include <iostream>
#include "vector"
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for(int i=0; i<nums1.size(); i++) {
        int l = 0;
        int r = (int) nums2.size();
        while (l<r) {
            int m = (l + r) / 2;
            if(nums1[i] > nums2[m]) {
                l = m + 1;
            } else if (nums1[i] < nums2[m]) {
                r = m;
            } else {
                result.push_back(nums1[i]);
                nums2.erase(nums2.begin() + m);
                break;
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v {1,2,2,1};
    vector<int> c {2,2};
    vector<int> result = intersect(v, c);
    for(int a: result)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
