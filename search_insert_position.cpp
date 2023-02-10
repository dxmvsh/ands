#include<iostream>
#include<vector>
using namespace std;

int binarySearch(int left, int right, vector<int>& nums, int target) {
    if (right - left == 1) {
        if (nums[left] == target || target < nums[left]) {
            return left;
        }
        if (nums[right] == target || target > nums[right]) {
            return right;
        }
        return ((left + right) / 2) + 1;
    }
    if (left == right) {
        return left;
    }
    int index = (left + right) / 2;
    int value = nums[index];
    if (target < value) {
        return binarySearch(left, index, nums, target);
    } else if (target > value) {
        return binarySearch(index, right, nums, target);
    } else {
        return index;
    }
}

int searchInsert(vector<int>& nums, int target) {
    if (nums[0] > target) {
        return 0;
    }
    if (nums[nums.size() - 1] < target) {
        return nums.size();
    }
    return binarySearch(0, nums.size() - 1, nums, target);
}

int main() {
    vector<int> nums;
    nums.push_back(6);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(10);
    int index = searchInsert(nums, 7);
    cout<<index<<endl;
    return 0;
}
