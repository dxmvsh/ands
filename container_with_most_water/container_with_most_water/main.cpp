//
//  main.cpp
//  container_with_most_water
//
//  Created by Strong on 09.03.2023.
//

#include <iostream>
#include "vector"
using namespace std;

int maxArea(vector<int>& height) {
    int result = 0;
    int n = (int) height.size();
    int l = 0, r = n - 1;
    while (l < r) {
        result = max(result, (r - l) * min(height[l], height[r]));
        if(height[l] < height[r])
            l++;
        else
            r--;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(v)<<endl;
    return 0;
}
