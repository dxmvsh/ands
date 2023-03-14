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

bool areAnagrams(string first, string second) {
    if(second.size() != first.size())
        return false;
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    return first == second;
}

bool hasGroupWithString(vector<vector<string>> v, string s) {
    for(int i=0; i<v.size(); i++) {
        if(areAnagrams(v[i][0], s))
            return true;
    }
    return false;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    if(!strs.size())
        return result;
    unordered_map<string, vector<int>> dictionary;
    vector<string> tmp = strs;
    for(int i=0; i<tmp.size(); i++) {
        sort(tmp[i].begin(), tmp[i].end());
        dictionary[tmp[i]].push_back(i);
    }
    for(auto element: dictionary) {
        vector<string> group;
        for(int index: element.second)
            group.push_back(strs[index]);
        result.push_back(group);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
    vector<vector<string>> groups = groupAnagrams(strs);
    for(vector<string> group: groups) {
        for(string element: group) {
            cout<<element<<" ";
        }
        cout<<endl;
    }
    return 0;
}
