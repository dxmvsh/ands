#include<iostream>
using namespace std;

int mySqrt(int x) {
    unsigned int result = x;
    if(x == 0) {
        return 0;
    }
    if(x == 1) {
        return 1;
    }
    unsigned int i;
    for(i=2; i*i <= result; i++) {
        if (i*i == result) {
            return i;
        }
    }
    return i - 1;
}

int main() {

    cout<<mySqrt(9)<<endl;

    return 0;
}
