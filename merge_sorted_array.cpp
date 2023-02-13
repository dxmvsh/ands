#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> result;
    int i = 0, j = 0;
    while(i < m || j < n) {
        if(i == m) {
            result.push_back(nums2[j]);
            j++;
            continue;
        }
        if(j == n) {
            result.push_back(nums1[i]);
            i++;
            continue;
        }
        int x = nums1[i];
        int y = nums2[j];
        if(i == m) {
            result.push_back(y);
            j++;
            continue;
        }
        if(j == n) {
            result.push_back(x);
            i++;
            continue;
        }
        if (x < y && i != m) {
            result.push_back(x);
            i++;
            continue;
        } 
        if (x > y && j != n) {
            result.push_back(y);
            j++;
            continue;
        } 
        if (x == y) {
            if (i != m) {
                result.push_back(x);
                i++;
                continue;
            }
            if (j != n) {
                result.push_back(j);
                j++;
                continue;
            }
        }
    }
    nums1 = result;
}

int main() {
    int arr1[] = { 1,2,3,0,0,0 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = { 2,5,6 };
    int m = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> nums1(arr1, arr1 + n);
    vector<int> nums2(arr2, arr2 + m);
    merge(nums1, 3, nums2, 3);
    for(int x: nums1) {
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}
