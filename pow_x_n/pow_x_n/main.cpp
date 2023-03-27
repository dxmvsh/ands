//
//  main.cpp
//  pow_x_n
//
//  Created by Dimash on 27.03.2023.
//  
//
	

#include <iostream>
using namespace std;

double myPow(double x, int n) {
    if(n < 0) {
        if (n == INT_MIN) {
            n++;
            n*=(-1);
            return 1 / (x * myPow(x, n));
        }
        else
            return 1 / myPow(x, -n);
    }
    if(!n) return 1;
    if(n == 1 || x == 1) return x;
    if(n % 2 == 0) {
        double pow = myPow(x, n/2);
        return pow * pow;
    }
    else
        return x * myPow(x, n-1);
}

int main(int argc, const char * argv[]) {
    cout<<myPow(2.00000, -2)<<endl;
    return 0;
}
