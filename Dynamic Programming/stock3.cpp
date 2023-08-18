#include<bits/stdc++.h> 
using namespace std;

int solveRec (vector<int>& prices, int n, int index, bool buy, int cap) {
    if (cap == 0) {
        return 0;
    }

    if (index == n) {
        return 0;
    }

    if (buy) {
        return max ((-prices[index] + solveRec (prices, n, index + 1, 0, cap)),
        (0 + solveRec (prices, n, index + 1, 1, cap)));
    }
    else {
        return max ((prices[index] + solveRec (prices, n, index + 1, 1, cap-1)),
        (0 + solveRec (prices, n, index + 1, 0, cap)));
    }
}

int solveMem (vector<int>& prices, int n, int index, int buy, int cap,
              vector<vector<vector<int>>> &dp) {
    if (cap == 0) {
        return 0;
    }

    if (index == n) {
        return 0;
    }

    if (dp[index][cap][buy] != -1) {
        return dp[index][cap][buy];
    }

    if (buy == 1) {
        return dp[index][cap][buy] = max ((-prices[index] + solveMem (prices, n, index + 1, 0, cap, dp)),
        (0 + solveMem (prices, n, index + 1, 1, cap, dp)));
    }
    else {
        return dp[index][cap][buy] = max ((prices[index] + solveMem (prices, n, index + 1, 1, cap-1, dp)),
        (0 + solveMem (prices, n, index + 1, 0, cap, dp)));
    }
}

int maxProfit(vector<int>& prices) {
    // 1 -> Recursion
    // int n = prices.size();
    // bool buy = 1;
    // int cap = 2;
    // int index = 0;
    // return solveRec (prices, n, index, buy, cap);

    // 2 -> Memoization
    // int n = prices.size();
    // int buy = 1;
    // int cap = 2;
    // int index = 0;
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(cap + 1, vector<int>(2, -1)));
    // return solveMem (prices, n, index, buy, cap, dp);

    // 3 -> Tabulation
    // Creating a 3d - dp of size [n+1][2][3] initialized to 0
    // int n = prices.size();
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));
                                            
    // // As dp array is intialized to 0, we have already covered the base case
    
    // for(int ind = n-1; ind>=0; ind--){
    //     for(int buy = 0; buy<=1; buy++){
    //         for(int cap=1; cap<=2; cap++){
                
    //             if(buy==0){// We can buy the stock
    //                 dp[ind][buy][cap] = max(0+dp[ind+1][0][cap], 
    //                             -prices[ind] + dp[ind+1][1][cap]);
    //              }
    
    //             if(buy==1){// We can sell the stock
    //                 dp[ind][buy][cap] = max(0+dp[ind+1][1][cap],
    //                             prices[ind] + dp[ind+1][0][cap-1]);
    //             }
    //         }
    //     }
    // }
    
    
    // return dp[0][0][2];

    int n = prices.size();
    vector<vector<int>> ahead(2,vector<int> (3,0));
    
    vector<vector<int>> cur(2,vector<int> (3,0));
    
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){// We can buy the stock
                    cur[buy][cap] = max(0+ahead[0][cap], 
                                -prices[ind] + ahead[1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    cur[buy][cap] = max(0+ahead[1][cap],
                                prices[ind] + ahead[0][cap-1]);
                }
            }
        }
        ahead = cur;
    }
    
    return ahead[0][2];
}