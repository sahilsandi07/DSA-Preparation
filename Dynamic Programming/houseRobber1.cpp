#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solveRec(vector<int> nums, int n) {
        // Base Case
        if (n < 0) return 0;
        if (n == 0) return nums[0];

        // if robber decides to rob this house
        int rob_house = solveRec(nums, n-2) + nums[n];

        // if he decides to skip this house
        int do_not_rob_house = solveRec(nums, n-1);

        return max(rob_house, do_not_rob_house);
    }

    int solveMem(vector<int> nums, int n, vector<int>&dp) {
        // Base Case
        if (n < 0) return 0;
        if (n == 0) return nums[0];

        // check for overlapping sub problems
        if (dp[n] != -1) return dp[n];

        // if robber decides to rob this house
        int rob_house = solveRec(nums, n-2) + nums[n];

        // if he decides to skip this house
        int do_not_rob_house = solveRec(nums, n-1);

        return dp[n] = max(rob_house, do_not_rob_house);
    }

    int solveTab(vector<int> &nums, int n) {
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i=1; i<n; i++) {
            int include_num = dp[i-2] + nums[i];
            int exclude_num = dp[i-1] + 0;

            dp[i] = max(include_num, exclude_num);
        }

        return dp[n-1];
    }

    int soveTabSO(vector<int> &nums, int n) {
        int prev2 = 0;
        int prev1 = nums[0];    

        for (int i=1; i<n; i++) {
            int include_num = prev2 + nums[i];
            int exclude_num = prev1 + 0;

            int ans = max(include_num, exclude_num);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        // 1 -> Recursion
        // int n = nums.size();
        // return solveRec (nums, n-1);

        // 2 -> Recursion with Memoization
        // int n = nums.size();
        // vector<int> dp(n, -1);
        // return solveMem (nums, n-1, dp);

        // 3 -> Tabularisation
        // int n = nums.size();
        // return solveTab(nums, n);

        // 4 -> Tabularisation with Space Optimisation
        int n = nums.size();
        return soveTabSO(nums, n);
    }
};