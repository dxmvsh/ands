//
//  main.cpp
//  valid_anagram
//
//  Created by Dimash on 27.02.2023.
//

#include <iostream>
#include "unordered_map"
using namespace std;

//bool isAnagram(string s, string t) {
//    if(s.size() != t.size()) {
//        return false;
//    }
//    unordered_map<char, int> charactersCount;
//    for(int i=0; i<s.size(); i++) {
//        if(!charactersCount[s[i]]) {
//            charactersCount[s[i]] = 1;
//        } else {
//            charactersCount[s[i]] += 1;
//        }
//    }
//    for(int i=0; i<t.size(); i++) {
//        if(charactersCount[t[i]] <= 0) {
//            return false;
//        }
//        charactersCount[t[i]]--;
//    }
//    return true;
//}
bool isAnagram(string s, string t) {
    if(s.size() != t.size())
        return false;
    int charCount[26]{0};
    int n = (int) s.size();
    for(int i=0; i<n; i++) {
        charCount[s[i]-'a']++;
        charCount[t[i]-'a']--;
    }
    for(int i=0; i<26; i++) {
        if(charCount[i])
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout<<isAnagram("anagram", "nagaram")<<endl;
    return 0;
}
