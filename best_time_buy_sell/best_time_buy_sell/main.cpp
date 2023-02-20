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
    int minPriceIndex = 0;
    for(int i=0; i<prices.size(); i++)
        minPriceIndex = min(prices[i], prices[minPriceIndex]) < prices[minPriceIndex] ? i : minPriceIndex;
    int maxPriceIndex = minPriceIndex;
    for(int i=minPriceIndex; i<prices.size(); i++)
        maxPriceIndex = max(prices[i], prices[maxPriceIndex]) > prices[maxPriceIndex] ? i : maxPriceIndex;
    return prices[maxPriceIndex] - prices[minPriceIndex];
}

int main(int argc, const char * argv[]) {
    vector<int> v {7,6,4,3,1};
    cout<<maxProfit(v)<<endl;
    return 0;
}
