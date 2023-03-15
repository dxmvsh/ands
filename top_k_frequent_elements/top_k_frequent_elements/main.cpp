//
//  main.cpp
//  top_k_frequent_elements
//
//  Created by Strong on 15.03.2023.
//

#include <iostream>
#include "vector"
#include "unordered_map"
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;

    unordered_map<int, int> count;
    
    for(int num: nums)
        count[num]++;
    
    vector<vector<int>> bucket(nums.size() + 1);
    
    for(auto element: count)
        bucket[element.second].push_back(element.first);
    
    for(int i = (int)bucket.size() - 1; i>=0 && result.size() < k; i--) {
        for(int j = 0; j<bucket[i].size() && result.size() < k; j++)
            result.push_back(bucket[i][j]);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> n = { 1,1,1,2,2,3 };
    vector<int> result = topKFrequent(n, 2);
    
    for(int a: result)
        cout<<a<<" ";
    
    return 0;
}
