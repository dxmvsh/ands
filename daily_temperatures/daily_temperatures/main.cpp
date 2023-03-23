//
//  main.cpp
//  daily_temperatures
//
//  Created by Dimash on 23.03.2023.
//

#include <iostream>
#include "vector"
#include "stack"
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result(temperatures.size(), 0);
    stack<int> tempStack;
    for(int i=0; i<temperatures.size(); i++) {
        while (!tempStack.empty() && temperatures[tempStack.top()] < temperatures[i]) {
            int index = tempStack.top();
            result[index] = i - index;
            tempStack.pop();
        }
        tempStack.push(i);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> v = {30,60,90};
    vector<int> result = dailyTemperatures(v);
    for(int a: result)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
