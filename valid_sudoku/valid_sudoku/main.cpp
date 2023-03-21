//
//  main.cpp
//  valid_sudoku
//
//  Created by Dimash on 19.03.2023.
//

#include <iostream>
#include "vector"
using namespace std;

bool isGroupValid(vector<vector<char>>& board, int i, int j, char check) {
    int ithGroup = i / 3, jthGroup = j / 3;
    int startRow = ithGroup * 3, startCol = jthGroup * 3;
    for(int row = startRow; row<startRow+3; row++) {
        for(int col = startCol; col<startCol+3; col++) {
            if(row == i && col == j) continue;
            if(board[row][col] == check)
                return false;
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    int n = 9;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == '.') continue;
            for(int k=0; k<n; k++) {
                if(k == j) continue;
                if(board[i][j] == board[i][k])
                    return false;
            }
            for(int k=0; k<n; k++) {
                if(k == i) continue;
                if(board[i][j] == board[k][j])
                    return false;
            }
            if(!isGroupValid(board, i, j, board[i][j])) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> v = {
        {'.','.','.','.','.','.','5','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'9','3','.','.','2','.','4','.','.'},
        {'.','.','7','.','.','.','3','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','3','4','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','.'},
        {'.','.','.','.','.','5','2','.','.'}
    };

    cout<<isValidSudoku(v)<<endl;
    return 0;
}
