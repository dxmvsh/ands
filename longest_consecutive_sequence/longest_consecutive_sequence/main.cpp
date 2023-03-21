//
//  main.cpp
//  longest_consecutive_sequence
//
//  Created by Dimash on 21.03.2023.
//

#include <iostream>
#include "vector"
#include "set"
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int result = 0  , n = (int) nums.size();
    set<int> numbersSet;
    for(int i=0; i<n; i++) {
        numbersSet.insert(nums[i]);
    }
    for(int i=0; i<n; i++) {
        if(numbersSet.find(nums[i] - 1) == numbersSet.end()) {
            int counter = 0, num = nums[i];
            while (numbersSet.find(num) != numbersSet.end()) {
                counter++;
                num++;
            }
            result = max(result, counter);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v = {100,4,200,1,3,2};
    cout<<longestConsecutive(v)<<endl;
    return 0;
}
