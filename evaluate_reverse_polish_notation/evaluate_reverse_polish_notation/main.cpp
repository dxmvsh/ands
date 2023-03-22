//
//  main.cpp
//  evaluate_reverse_polish_notation
//
//  Created by STRONG on 22.03.2023.
//

#include <iostream>
#include "vector"
#include "stack"
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> numbers;
    for(string token: tokens) {
        if(token == "+" || token == "-" || token == "*" || token == "/") {
            int second = numbers.top();
            numbers.pop();
            int first = numbers.top();
            numbers.pop();
            if (token == "+")
                numbers.push(first + second);
            else if (token == "-")
                numbers.push(first - second);
            else if (token == "*")
                numbers.push(first * second);
            else if (token == "/")
                numbers.push(first / second);
        } else {
            int number = stoi(token);
            numbers.push(number);
        }
    }
    return numbers.top();
}

int main(int argc, const char * argv[]) {
    vector<string> v = {"4","13","5","/","+"};
    cout<<evalRPN(v)<<endl;
    return 0;
}
