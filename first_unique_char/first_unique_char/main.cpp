//
//  main.cpp
//  first_unique_char
//
//  Created by Strong on 08.03.2023.
//

#include <iostream>
#include "unordered_map"
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> charIndices;
    charIndices[s[0]] = 0;
    for(int i=1; i<s.size(); i++) {
        if(charIndices.find(s[i]) != charIndices.end())
            charIndices[s[i]] = -1;
        else
            charIndices[s[i]] = i;
    }
    int minIndex = INT_MAX;
    for(auto i=charIndices.begin(); i != charIndices.end(); ++i) {
        if(i->second != -1)
            minIndex = min(minIndex, i->second);
    }
    return minIndex == INT_MAX ? -1 : minIndex;
}

int main(int argc, const char * argv[]) {
    cout<<firstUniqChar("aabqb")<<endl;
    return 0;
}
