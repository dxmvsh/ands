//
//  main.cpp
//  rotate_image
//
//  Created by Dimash on 25.03.2023.
//  
//

#include <iostream>
#include "vector"
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> v = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    rotate(v);
    for(vector<int> a: v) {
        for(int b: a) {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/**
 1 2 3
 4 5 6
 7 8 9

 
 */
