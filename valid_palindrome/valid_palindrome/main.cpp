//
//  main.cpp
//  valid_palindrome
//
//  Created by Strong on 21.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

bool isPalindrome(string s) {
    vector<char> characters;
    for(int i=0; i<s.size(); i++) {
        if(s[i] - 'a' >= 0 && s[i] - 'a' <= 25)
            characters.push_back(s[i]);
        else if(s[i] - 'A' >= 0 && s[i] -'A' <= 25)
            characters.push_back(s[i] - 'A' + 'a');
        else if(s[i] - '0' >= 0 && s[i] - '0' <=9)
            characters.push_back(s[i]);
    }
    for(int i=0; i<characters.size(); i++) {
        if(characters[characters.size() - 1 - i] != characters[i])
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    string s = "0P0";
    cout<<isPalindrome(s)<<endl;
    return 0;
}
