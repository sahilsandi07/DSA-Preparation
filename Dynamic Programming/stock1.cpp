#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    int currMin = prices[0];
    int maxProfit = 0;
    int n = prices.size();

    for (int i=1; i<n; i++) {
        int cost = prices[i] - currMin;
        maxProfit = max (maxProfit, cost);
        currMin = min (currMin, prices[i]);
    }

    return maxProfit;
}