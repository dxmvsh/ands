//
//  main.cpp
//  minstack
//
//  Created by STRONG on 22.03.2023.
//

#include <iostream>
#include "vector"
using namespace std;

class MinStack {
public:

    vector<vector<int>> elements;
    MinStack() {}
    void push(int val) {
        vector<int> element(2, val);
        if(!elements.empty())
            element[1] = min(val, elements[elements.size() - 1][1]);
        elements.push_back(element);
    }
    
    void pop() {
        elements.erase(elements.end() - 1);
    }
    
    int top() {
        return elements[elements.size() - 1][0];
    }
    
    int getMin() {
        return elements[elements.size() - 1][1];
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
