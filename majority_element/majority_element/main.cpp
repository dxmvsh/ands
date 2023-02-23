//
//  main.cpp
//  majority_element
//
//  Created by Strong on 23.02.2023.
//

#include <iostream>
#include "vector"
#include "map"
#include "unordered_map"
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    int element = 0;
    int maxOccurrences = -1;
    for(int i=0; i<nums.size(); i++) {
        map[nums[i]]++;
        if(map[nums[i]] > maxOccurrences) {
            element = nums[i];
            maxOccurrences = map[nums[i]];
        }
    }
    return element;
}

int main(int argc, const char * argv[]) {
    vector<int> v {3,2,3};
    cout<<majorityElement(v)<<endl;
    return 0;
}
