//
//  main.cpp
//  generate_parentheses
//
//  Created by STRONG on 22.03.2023.
//

#include <iostream>
#include "vector"
#include "stack"
using namespace std;

void generate(vector<string> &result, string s, int open, int closed) {
    if(open == 0 && closed == 0) {
        result.push_back(s);
        return;
    }
    if(open>0) {
        generate(result, s+"(", open - 1, closed);
    }
    if(closed>open) {
        generate(result, s+")", open, closed-1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generate(result, "", n, n);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> result = generateParenthesis(3);
    for(string element: result)
        cout<<element<<" ";
    cout<<endl;
    return 0;
}
