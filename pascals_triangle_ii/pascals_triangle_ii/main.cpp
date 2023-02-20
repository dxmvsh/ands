//
//  main.cpp
//  pascals_triangle_ii
//
//  Created by Strong on 20.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

vector<int> addVectors(vector<int> a, vector<int> b) {
    a.insert(a.begin(), 0);
    b.push_back(0);
    vector<int> result(a.size());
    for(int i=0; i<result.size(); i++)
        result[i] = a[i] + b[i];
    return result;
}

vector<int> getRow(int rowIndex) {
    vector<int> result = { 1 };
    for(int i=0; i<rowIndex; i++) {
        result = addVectors(result, result);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> result = getRow(3);
    for(int i=0; i<result.size(); i++)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
