#include <bits/stdc++.h> 
using namespace std;
int recSolve (vector<int>&coins, int amount) {
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int i=0; i<coins.size(); i++) {
        int minCoins = recSolve(coins, amount - coins[i]);

        if (minCoins != INT_MAX) {
            mini = min(mini, minCoins + 1);
        }
    }

    return mini;
}

int memSolve (vector<int>&coins, int amount, vector<int> &dp) {
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return INT_MAX;
    }

    if (dp[amount] != -1) {
        return  dp[amount];
    }

    int mini = INT_MAX;
    for (int i=0; i<coins.size(); i++) {
        int minCoins = memSolve(coins, amount - coins[i], dp);

        if (minCoins != INT_MAX) {
            mini = min(mini, minCoins + 1);
        }
    }

    dp[amount] = mini;

    return mini;
}

int tabSolve (vector<int>&coins, int amount) {
    
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i=1; i<=amount; i++) {
        for (int j=0; j<coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min (dp[i], 1 + dp[i-coins[j]]);
            }
        }
    }

    // Debug print statements
    // cout << "DP Array: ";
    // for (int i = 0; i <= amount; i++) {
    //     if (dp[i] == INT_MAX) {
    //         cout << "INF ";
    //     } else {
    //         cout << dp[i] << " ";
    //     }
    // }
    // cout << endl;

    if (dp[amount] == INT_MAX) return -1;
    else return dp[amount];
}

int minimumElements(vector<int> &num, int x) {
    // 1 -> Reccursion
    // int ans = recSolve (num, x);
    // if (ans != INT_MAX) return ans;
    // else return -1;  

    // 2 -> Memoization  
    // vector<int> dp(x+1, -1);
    // int ans = memSolve(num, x, dp);
    // if (ans != INT_MAX) {
    //     return ans;
    // }
    // else {
    //     return -1;
    // }

    // 3 -> Tabularisation
    return tabSolve(num, x);
}

int main () {
    vector<int> coins = {2, 4, 5};
    int amount = 15;
    cout << "Coins Required: " << minimumElements(coins, amount) << endl;
    return 0;
}