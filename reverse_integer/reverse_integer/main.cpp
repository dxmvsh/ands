//
//  main.cpp
//  reverse_integer
//
//  Created by Strong on 08.03.2023.
//

#include <iostream>
using namespace std;

int reverse(int x) {
    int result = 0;
    while (x != 0) {
        int digit = x % 10;
        if(result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
            return 0;
        if(result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < INT_MIN % 10))
            return 0;
        x /= 10;
        result *= 10;
        result += digit;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<reverse(1534236469)<<endl;
    return 0;
}
