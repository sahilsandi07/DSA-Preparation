#include<bits.stdc++.h>
using namespace std;

class Solution {
    private:
    int helper (int n, vector<int> & cost) {
        // Base Case
        if (n == 0) {
            return cost[0];
        }
        if (n == 1) {
            return cost[1];
        }

        int ans = min (helper(n-1, cost), helper(n-2, cost)) + cost[n];

        return ans;
    }

    int helper2 (int n, vector<int> &cost, vector<int> &dp) {
        // Base Case
        if (n == 0) {
            return cost[0];
        }
        if (n == 1) {
            return cost[1];
        }

        // Step 3
        if (dp[n] != -1) {
            return dp[n];
        }

        //Step 2
        return dp[n] = min (helper2(n-1, cost, dp), helper2(n-2, cost, dp)) + cost[n];
    }

    int helper3 (int n, vector<int> &cost) {
        // step 1
        vector<int> dp (n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        // step 2
        for (int i=2; i<n; i++) {
            dp[i] = cost[i] + min (dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }

    int helper4 (int n, vector<int> &cost) {
        // step 1
        int prev2 = cost[0];
        int prev1 = cost[1];

        // step 2
        for (int i=2; i<n; i++) {
            int curr = cost[i] + min (prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
 
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 1 -> Recursion Solution
        // int n = cost.size();
        // int ans = min (helper(n-1, cost), helper(n-2, cost));
        // return ans;

        // 2 -> Recursion with Memoization
        // int n = cost.size();
        // vector<int> dp(n+1, -1);
        // int ans = min (helper2(n-1, cost, dp), helper2(n-2, cost, dp));
        // return ans;

        // 3 -> Tabularisation
        // int n = cost.size();
        // return helper3 (n, cost);

        // 4 -> Tabularisation With Sapce Optimisation
        int n = cost.size();
        return helper4 (n, cost);
    }
};