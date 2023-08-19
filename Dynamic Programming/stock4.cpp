#include <bits/stdc++.h> 
using namespace std;
int rec (int ind, int tranNo, vector<int> &prices, int n, int k) {
    if (ind == n || tranNo == k*2) {
        return 0;
    }
    if (tranNo % 2 == 0) {
        return max (-prices[ind] + rec(ind + 1, tranNo + 1, prices, n, k),
                0 + rec (ind + 1, tranNo, prices, n, k));
    }
    return max (prices[ind] + rec (ind + 1, tranNo + 1, prices, n, k),
                0 + rec (ind + 1, tranNo, prices, n, k));
}

int mem (int ind, int tranNo, vector<int> &prices, int n, int k, vector<vector<int>> &dp) {
    if (ind == n || tranNo == k*2) {
        return 0;
    }
    if (dp[ind][tranNo] != -1) return dp[ind][tranNo];
    if (tranNo % 2 == 0) {
        return dp[ind][tranNo] = max (-prices[ind] + mem(ind + 1, tranNo + 1, prices, n, k, dp),
                0 + mem (ind + 1, tranNo, prices, n, k, dp));
    }
    return dp[ind][tranNo] = max (prices[ind] + mem (ind + 1, tranNo + 1, prices, n, k, dp),
                0 + mem (ind + 1, tranNo, prices, n, k, dp));
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // return rec (0, 0, prices, n, k);
    // vector<vector<int>> dp (n, vector<int>(2*k, -1));
    // return mem (0, 0, prices, n, k, dp);
    vector<vector<int>> dp (n+1, vector<int>(2*k + 1, 0));

    for (int ind = n-1; ind >= 0; ind --) {
        for (int tranNo = 2*k - 1; tranNo >= 0; tranNo --) {
            if (tranNo % 2 == 0) {
                dp[ind][tranNo] = max (-prices[ind] + dp[ind + 1][tranNo + 1],
                                        dp[ind + 1][tranNo]);
            }
            else dp[ind][tranNo] = max (prices[ind] + dp[ind + 1][tranNo + 1],
                                        dp[ind + 1][tranNo]);
        }
    }
    return dp[0][0];
}
