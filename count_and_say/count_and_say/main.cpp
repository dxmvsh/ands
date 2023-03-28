//
//  main.cpp
//  count_and_say
//
//  Created by Dimash on 27.03.2023.
//  
//

#include <iostream>
#include "unordered_map"
using namespace std;

string countAndSay(int n) {
    string base = "1";
    for(int i=1; i<n; i++) {
        int count = 0;
        char currentChar = 'a';
        string newBase;
        for(int j=0; j<base.size(); j++) {
            if(currentChar != base[j]) {
                if(count) {
                    newBase += (char)(count + '0');
                    newBase += currentChar;
                    count = 1;
                } else {
                    count++;
                }
                currentChar = base[j];
            } else {
                count++;
            }
        }
        newBase += (char)(count + '0');
        newBase += currentChar;
        base = newBase;
    }
    return base;
}

int main(int argc, const char * argv[]) {
    cout<<countAndSay(8)<<endl;
    return 0;
}
//111221
//312211
//13112221
//1113213211
