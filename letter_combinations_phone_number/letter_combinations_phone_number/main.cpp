//
//  main.cpp
//  letter_combinations_phone_number
//
//  Created by Strong on 13.03.2023.
//

#include <iostream>
#include "vector"
using namespace std;

vector<vector<char>> dictionary = {
    {'a','b','c'},
    {'d','e','f'},
    {'g','h','i'},
    {'j','k','l'},
    {'m','n','o'},
    {'p','q','r','s'},
    {'t','u','v'},
    {'w','x','y','z'}
};

int permutationsCount(string digits) {
    if(digits.empty())
        return 0;
    int result = 1;
    for(int i=0; i<digits.size(); i++) {
        int digitIndex = (digits[i] - '0') - 2;
        result *= dictionary[digitIndex].size();
    }
    return result;
}

vector<int> nextPermutation(string digits, vector<int> v) {
    int i = (int) v.size() - 1;
    int remainder = 1;
    while (remainder && i>=0) {
        v[i] += remainder;
        int digitIndex = (digits[i] - '0') - 2;
        if(v[i] == dictionary[digitIndex].size()) {
            v[i] = 0;
            i--;
        } else {
            remainder = 0;
        }
    }
    return v;
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.empty())
        return result;
    int n = (int) digits.size();
    vector<int> positionedIndices(n, 0);
    int permutationsSize = permutationsCount(digits), counter = 0;
    while (counter < permutationsSize) {
        string combination;
        for(int i=0; i<positionedIndices.size(); i++) {
            int digitIndex = (digits[i] - '0') - 2;
            combination = combination + dictionary[digitIndex][positionedIndices[i]];
        }
        result.push_back(combination);
        positionedIndices = nextPermutation(digits, positionedIndices);
        counter++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> result = letterCombinations("23");
    for(string element: result)
        cout<<element<<endl;
    return 0;
}
