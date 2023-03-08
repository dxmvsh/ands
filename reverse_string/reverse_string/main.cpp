//
//  main.cpp
//  reverse_string
//
//  Created by Strong on 08.03.2023.
//

#include <iostream>
#include "vector"
using namespace std;

void reverseString(vector<char>& s) {
    int n = (int) s.size();
    for(int i=0; i<n / 2; i++) {
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
    for(int i=0; i<n; i++) {
        cout<<s[i];
    }
}

int main(int argc, const char * argv[]) {
    string s = "hello";
    vector<char> v;
    for(int i=0; i<s.size(); i++)
        v.push_back(s[i]);
    reverseString(v);
    return 0;
}
