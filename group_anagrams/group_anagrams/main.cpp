//
//  main.cpp
//  group_anagrams
//
//  Created by Strong on 14.03.2023.
//

#include <iostream>
#include "vector"
#include "unordered_map"
using namespace std;

long long int hashString(string s) {
    long long constant = 1e12;
    vector<int> n = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
    long long int result = 1;
    for(char c: s) {
        int index = c - 'a';
        result *= n[index];
        result %= constant;
    }
    return result;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    if(!strs.size())
        return result;
    unordered_map<long long int, vector<string>> dictionary;
    for(int i=0; i<strs.size(); i++) {
        string s = strs[i];
        dictionary[hashString(s)].push_back(s);
    }
    for(auto element: dictionary) {
        result.push_back(element.second);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> strs = { "ddddddddddg","dgggggggggg" };
    vector<vector<string>> groups = groupAnagrams(strs);
    for(vector<string> group: groups) {
        for(string element: group) {
            cout<<element<<" ";
        }
        cout<<endl;
    }
    return 0;
}
