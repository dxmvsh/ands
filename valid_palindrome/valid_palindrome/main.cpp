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
    int l = 0, r = (int) s.size() - 1;
    while (l < r) {
        while (l<r && !isalnum(s[l])) {
            l++;
        }
        while (l<r && !isalnum(s[r])) {
            r--;
        }
        if(tolower(s[l++]) != tolower(s[r--]))
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    string s = "race a ecar";
    cout<<isPalindrome(s)<<endl;
    return 0;
}
