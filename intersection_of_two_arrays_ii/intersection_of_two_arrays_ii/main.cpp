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
    for(int i=0; i<nums1.size(); i++) {
        for(int j=0; j<nums2.size(); j++) {
            if(nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                nums2.erase(nums2.begin() + j);
                break;
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v {4,9,5};
    vector<int> c {9,4,9,8,4};
    vector<int> result = intersect(v, c);
    for(int a: result)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
