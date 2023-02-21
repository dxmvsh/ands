//
//  main.cpp
//  best_time_buy_sell
//
//  Created by Strong on 20.02.2023.
//

#include <iostream>
#include "vector"
using namespace std;

int maxProfit(vector<int>& prices) {
    int minimumValue = prices[0];
    int profit = 0;
    int currentDaySellProfit = 0;
    
    for(int i=0; i<prices.size(); i++) {
        minimumValue = min(minimumValue, prices[i]);
        currentDaySellProfit = prices[i] - minimumValue;
        profit = max(profit, currentDaySellProfit);
    }
    
    return profit;
}

int main(int argc, const char * argv[]) {
    vector<int> v {7,2,4,1};
    cout<<maxProfit(v)<<endl;
    return 0;
}
