//
//  main.cpp
//  move_zeroes
//
//  Created by Strong on 28.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;
//void moveZeroes(vector<int>& nums) {
//    int zeroesCount = 0;
//    for(int i=0; i<nums.size(); i++) {
//        if(nums[i])
//            zeroesCount++;
//    }
//    int zeroIndex = -1;
//    int nonZeroIndex = 0;
//    int i = 0;
//    while (i < nums.size() && zeroesCount != 0) {
//        if(!nums[i]) {
//            zeroIndex = i;
//            nonZeroIndex = zeroIndex;
//            while(nonZeroIndex < nums.size() && nums[nonZeroIndex] == 0)
//                nonZeroIndex++;
//            if(nonZeroIndex >= nums.size())
//                return;
//            if (nonZeroIndex != zeroIndex)
//                swap(nums[zeroIndex], nums[nonZeroIndex]);
//            zeroesCount--;
//        }
//        i++;
//    }
//    for(int a: nums)
//        cout<<a<<" ";
//    cout<<endl;
//}
void moveZeroes(vector<int>& nums) {
    int zeroesCount = 0;
    for(int i=0; i<nums.size(); i++) {
        if(!nums[i])
            zeroesCount++;
        else if (zeroesCount > 0)
            swap(nums[i], nums[i - zeroesCount]);
    }
    for(int a: nums)
        cout<<a<<" ";
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    vector<int> v {0,1,0,2,12};
    moveZeroes(v);
    return 0;
}
