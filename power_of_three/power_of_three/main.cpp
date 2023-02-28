//
//  main.cpp
//  power_of_three
//
//  Created by Strong on 28.02.2023.
//

#include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
    if(!n)
        return false;
    while (n != 1) {
        if(n % 3 != 0)
            return false;
        n /= 3;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout<<isPowerOfThree(-3)<<endl;
    return 0;
}
