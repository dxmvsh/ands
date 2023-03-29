//
//  main.cpp
//  spiral_matrix
//
//  Created by Dimash on 29.03.2023.
//

#include <iostream>
#include "vector"
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int m = (int)matrix.size();
    int n = 0;
    if(m) {
        n = (int) matrix[0].size();
    }
    int i=0, j=0;
    int minI = i, minJ = j;
    int totalCount = m * n;
    while (result.size() < totalCount) {
        for(; j<n; j++) {
            result.push_back(matrix[i][j]);
        }
        if(result.size() >= totalCount) {
            break;
        }
        j--;
        i++;
        for(; i<m; i++) {
            result.push_back(matrix[i][j]);
        }
        if(result.size() >= totalCount) {
            break;
        }
        m--;
        n--;
        i--;
        j--;
        for(; j >= minJ; j--) {
            result.push_back(matrix[i][j]);
        }
        if(result.size() >= totalCount) {
            break;
        }
        j++;
        i--;
        for(; i != minI; i--) {
            result.push_back(matrix[i][j]);
        }
        i++;
        j++;
        minI++;
        minJ++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> v = {
        {1},
        {2},
        {3},
    };
    vector<int> result = spiralOrder(v);
    for(int a: result)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
