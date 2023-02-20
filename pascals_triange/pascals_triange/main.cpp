//
//  main.cpp
//  pascals_triange
//
//  Created by Strong on 20.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    for(int i = 0; i<numRows; i++) {
        if(!i) {
            result.push_back({ 1 });
            continue;
        }
        vector<int> lastRow = result[result.size() - 1];
        int lastRowSize = (int) lastRow.size();
        if(lastRowSize - 2 >= 0) {
            int rowSize = lastRowSize + 1;
            vector<int> row(rowSize);
            
            for(int j=0; j<rowSize; j++) {
                if(j == 0 || j == rowSize - 1) {
                    row[j] = 1;
                    continue;
                }
                row[j] = lastRow[j-1] + lastRow[j];
            }
            result.push_back(row);
        } else {
            result.push_back({1, 1});
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> result = generate(5);
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
