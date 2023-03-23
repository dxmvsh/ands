//
//  main.cpp
//  car_fleet
//
//  Created by Dimash on 23.03.2023.
//

#include <iostream>
#include "vector"
#include "stack"
using namespace std;

bool comparePair(pair<int, int> left, pair<int, int> right) {
    return left.first < right.first;
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = (int) position.size();
    vector<pair<int, int>> v;
    stack<double> times;
    for(int i=0; i<n; i++)
        v.push_back(make_pair(position[i], speed[i]));
    sort(v.begin(), v.end(), comparePair);
    for(int i = n - 1; i>=0; i--) {
        int distance = target - v[i].first;
        double time = (double) distance / (double) v[i].second;
        if(times.empty()) {
            times.push(time);
            continue;
        }
        double lastTime = times.top();
        if(time > lastTime)
            times.push(time);
    }
    return (int) times.size();
}

int main(int argc, const char * argv[]) {
    vector<int> position = { 6,8 }, speed = { 3,2 };
    cout<<carFleet(10, position, speed)<<endl;
    return 0;
}
