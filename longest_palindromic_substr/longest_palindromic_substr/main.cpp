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

//string longestPalindrome(string s) {
//    string result;
//    int n = (int) s.size();
//    int longestPalindromeStart = 0, longestPalindromeSize = -1;
//    if(n < 2)
//        return s;
//    for(int i=0; i<n; i++) {
//        int right = i;
//        while (right < n && s[i] == s[right])
//            right++;
//        int left = i - 1;
//        while (left >= 0 && right < n && s[left] == s[right]) {
//            left--;
//            right++;
//        }
//        int size = right - left - 1;
//        if(size>longestPalindromeSize) {
//            longestPalindromeSize = size;
//            longestPalindromeStart = left + 1;
//        }
//    }
//    return s.substr(longestPalindromeStart, longestPalindromeSize);
//}

string longestPalindrome(string s) {
    int n = (int) s.size();
    int maxSize = 0;
    string result;
    vector<vector<bool>> matrix(n, vector<bool>(n, false));
    for(int i=0; i<n; i++) {
        matrix[i][i] = true;
        if(i == n - 1) break;
        matrix[i][i+1] = s[i] == s[i+1];
    }
    for(int i=n-3; i>=0; i--) {
        for(int j=i+2; j<n; j++) {
            matrix[i][j] = (matrix[i+1][j-1] && s[i] == s[j]);
            if(matrix[i][j] && j-i+1>maxSize) {
                maxSize = j-i+1;
                result = s.substr(i, maxSize);
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<longestPalindrome("abbacqoqoqoqzxcv")<<endl;
    return 0;
}
/*
 abbacqoqoqoqzxcv
   a c c a
 a 1 0 0 1
 c   1 1 0
 c     1 0
 a       1
   a b b a c q o q o q o q z x c v
 a 1 0 0 1
 b   1 1
 b     1
 a       1
 c         1
 q           1
 o             1
 q               1
 o                 1
 q                   1
 o                     1
 q                       1
 z                         1
 x                           1   0
 c                             1
 v                               1
*/
