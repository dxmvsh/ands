//
//  main.cpp
//  is_happy
//
//  Created by Dimash on 25.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

int sumOfSquaredDigits(int n) {
    vector<int> digits;
    while (n != 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    int sum = 0;
    for(int digit: digits)
        sum += (digit * digit);
    if(sum == 1)
        return true;
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = n;
    
    do {
        slow = sumOfSquaredDigits(slow);
        fast = sumOfSquaredDigits(fast);
        fast = sumOfSquaredDigits(fast);
        
    } while (slow != fast);
    if(slow == 1)
        return true;
    return false;
}

int main(int argc, const char * argv[]) {
    cout<<isHappy(2)<<endl;
    return 0;
}
