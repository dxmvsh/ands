//
//  main.cpp
//  product_of_array_except_self
//
//  Created by Dimash on 18.03.2023.
//

#include <iostream>
#include "vector"
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = (int) nums.size();
    vector<int> result(n,0);
    int product = 1;
    for(int i=0; i<n; i++) {
        result[i] = product;
        product *= nums[i];
    }
    product = 1;
    for(int i=n-1; i>=0; i--) {
        result[i] *= product;
        product *= nums[i];
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v = {-1,1,0,-3,3};
    vector<int> result = productExceptSelf(v);
    for(int num: result) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
