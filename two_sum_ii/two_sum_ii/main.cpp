//
//  main.cpp
//  two_sum_ii
//
//  Created by STRONG on 22.03.2023.
//

#include <iostream>
#include "vector"
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result(2,0);
    int l = 0, r = ((int) numbers.size()) - 1;
    while (l < r) {
        int sum = numbers[l] + numbers[r];
        if(sum < target) {
            l++;
        } else if (sum > target) {
            r--;
        } else {
            result[0] = l + 1;
            result[1] = r + 1;
            break;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v = { -1,0 };
    vector<int> result = twoSum(v, -1);
    for(int n: result)
        cout<<n<<" ";
    cout<<endl;
    return 0;
}
