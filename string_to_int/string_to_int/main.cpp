//
//  main.cpp
//  string_to_int
//
//  Created by Strong on 08.03.2023.
//

#include <iostream>
using namespace std;

bool isOutOfMinBounds(int n, int d) {
    return (n < INT_MIN / 10 || (n == INT_MIN / 10 && d > INT_MIN % 10));
}
bool isOutOfMaxBounds(int n, int d) {
    return (n > INT_MAX / 10 || (n == INT_MAX / 10 && d > INT_MAX % 10));
}
bool isDigit(char c) {
    return c - '0' >= 0 && c - '0' <= 9;
}
bool isIgnorableCharacter(char c) {
    return c == ' ' || c == '-' || c == '+';
}
bool isSign(char c) {
    return c == '-' || c == '+';
}
int myAtoi(string s) {
    int result = 0;
    bool isNegative = false, hasBeenSignBefore = false, hasBeenDigitBefore = false;
    string filtered = "";
    for(int i=0; i<s.size(); i++) {
        char c = s[i];
        if(isDigit(c) || isSign(c)) {
            filtered += c;
        }
        else if (c == ' ') {
            if (!filtered.empty())
                break;
        }
        else {
            break;
        }
    }
    for(int i=0; i<filtered.size(); i++) {
        char c = filtered[i];
        if(isSign(c)) {
            if(hasBeenSignBefore || hasBeenDigitBefore)
                return isNegative ? -result : result;
            if(c == '-')
                isNegative = true;
            hasBeenSignBefore = true;
            continue;
        }
        hasBeenDigitBefore = true;
        int digit = c - '0';
        if(isOutOfMaxBounds(result, digit) || isOutOfMinBounds(result, digit))
            return isNegative ? INT_MIN : INT_MAX;
        result *= 10;
        result += digit;
    }
    return isNegative ? -result : result;
}

int main(int argc, const char * argv[]) {
    cout<<myAtoi(" -12341234 words and 987")<<endl;
    cout<<myAtoi("00000-42a1234")<<endl;
    cout<<myAtoi("     -42")<<endl;
    cout<<myAtoi("+-42")<<endl;
    cout<<myAtoi("4193 with words")<<endl;
    cout<<myAtoi("-2147483647")<<endl;
    cout<<myAtoi("-2147483649")<<endl;
    cout<<myAtoi("-5-")<<endl;
    return 0;
}
