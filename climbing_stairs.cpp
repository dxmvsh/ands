#include<iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    int nMinus2 = 1;
    int nMinus1 = 1;
    int ans;
    
    for(int i=2; i<=n; i++) {
        ans = nMinus2 + nMinus1;
        nMinus2 = nMinus1;
        nMinus1 = ans;
    }

    return ans;
}

int main() {
    for(int i=1; i<=6; i++) {
        cout<<climbStairs(i)<<" ";
    }
    return 0;
}
