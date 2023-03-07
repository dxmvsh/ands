//
//  main.cpp
//  longest_palindromic_substr
//
//  Created by Strong on 07.03.2023.
//

#include <iostream>
#include "unordered_map"
#include "vector"
using namespace std;

bool isPalindrome(string s, int start, int end) {
    int i=start, j=end;
    while (i<j) {
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

string longestPalindrome(string s) {
    string result;
    int n = (int) s.size();
    int longestPalindromeStart = 0, longestPalindromeSize = -1;
    if(n < 2)
        return s;
    for(int i=0; i<n; i++) {
        int right = i;
        while (right < n && s[i] == s[right])
            right++;
        int left = i - 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        int size = right - left - 1;
        if(size>longestPalindromeSize) {
            longestPalindromeSize = size;
            longestPalindromeStart = left + 1;
        }
    }
    return s.substr(longestPalindromeStart, longestPalindromeSize);
}

int main(int argc, const char * argv[]) {
    cout<<longestPalindrome("acca")<<endl;
    return 0;
}
/*
 abbacqoqoqoqzxcv
*/
