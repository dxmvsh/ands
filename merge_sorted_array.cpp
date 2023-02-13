#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1, j = n-1, k = m+n-1;
    while(j>=0 && i>=0) {
        if(nums2[j] > nums1[i]) {
            nums1[k--] = nums2[j--];
        } else {
            nums1[k--] = nums1[i--];
        }
    }
    while(j>=0) {
        nums1[k--] = nums2[j--];
    }
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
