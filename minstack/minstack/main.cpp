//
//  main.cpp
//  minstack
//
//  Created by STRONG on 22.03.2023.
//

#include <iostream>
#include "vector"
#include "stack"
using namespace std;

class MinStack {
public:

    stack<int> elements;
    stack<int> minimumElements;
    MinStack() {}
    void push(int val) {
        elements.push(val);
        int minimumValue;
        if(minimumElements.empty())
            minimumValue = val;
        else
            minimumValue = min(val, minimumElements.top());
        minimumElements.push(minimumValue);
    }
    
    void pop() {
        elements.pop();
        minimumElements.pop();
    }
    
    int top() {
        return elements.top();
    }
    
    int getMin() {
        return minimumElements.top();
    }
    
};

int main(int argc, const char * argv[]) {
    MinStack* s = new MinStack();
    s->push(-2);
    s->push(0);
    s->push(-3);
    cout<<s->getMin()<<endl;
    s->pop();
    cout<<s->top()<<endl;
    cout<<s->getMin()<<endl;
    
    return 0;
}
