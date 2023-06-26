#include <bits/stdc++.h> 
using namespace std;

int solveRec (vector<int> num, int target) {
    // base case
    if (target == 0) return 1;
    if (target < 0) return 0;

    // check for all possible ways
    int ways = 0;
    for (int i=0; i<num.size(); i++) {
        ways += solveRec (num, target-num[i]);
    }

    return ways;
}

int solveMem (vector<int> &num, int target, vector<int> &dp) {
    // base case
    if (target == 0) return 1;
    if (target < 0) return 0;

    // check for overlapping sub problems
    if (dp[target] != -1) return dp[target];

    // check for all possible ways
    int ways = 0;
    for (int i=0; i<num.size(); i++) {
        ways += solveMem (num, target-num[i], dp);
    }

    return dp[target] = ways;
}

int solveTab (vector<int> &num, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i=1; i<=target; i++) {
        for (int j=0; j<num.size(); j++) {
            if (i - num[j] >= 0) dp[i] += dp [i - num[j]];
        }
    }

    return dp[target];
}

int findWays(vector<int> &num, int tar)
{
    // 1 -> Recursion
    // return solveRec(num, tar);

    // 2 -> Memoization
    vector<int> dp(tar + 1, -1);
    return solveMem (num, tar, dp);

    // 3 -> Tabulation
    // return solveTab (num, tar);
}