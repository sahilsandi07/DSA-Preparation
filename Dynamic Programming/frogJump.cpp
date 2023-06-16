#include <bits/stdc++.h> 
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp (n, 0);
    dp[0] = 0;
    for (int i=1; i<n; i++) {
        int first = dp[i-1] + abs(heights[i-1] - heights[i]);
        int right = INT_MAX;
        if (i > 1) {
            right = dp[i-2] + abs(heights[i-2] - heights[i]);
        }

        dp[i] = min (first, right);
    }

    return dp[n-1];    
}