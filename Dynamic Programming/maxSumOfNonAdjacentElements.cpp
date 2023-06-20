#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &nums, int n) {
    // Base Case
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return nums[0];
    }

    // if suppose we have {9, 1, 8, 9}
    // and we decide to include 9
    int include_num = solveRec(nums, n-2) + nums[n];

    // if suppose we exclude 9 we will move ahed by one
    // position 
    int exclude_num = solveRec(nums, n-1);

    return max(include_num, exclude_num);
}

int solveMem(vector<int> &nums, int n, vector<int> &dp) {
    // Base Case
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return nums[0];
    }

    if (dp[n] != -1) return dp[n];

    // if suppose we have {9, 1, 8, 9}
    // and we decide to include 9
    int include_num = solveMem(nums, n-2, dp) + nums[n];

    // if suppose we exclude 9 we will move ahed by one
    // position 
    int exclude_num = solveMem(nums, n-1, dp);

    return dp[n] = max(include_num, exclude_num);
}

int soveTab(vector<int> &nums, int n) {
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

int maximumNonAdjacentSum(vector<int> &nums){
    // 1 -> Recursion
    // int n = nums.size();
    // return solveRec(nums, n-1);

    // 2 -> Recursion with Memoization
    // int n = nums.size();
    // vector<int> dp (n, -1);
    // return solveMem(nums, n-1, dp);

    // 3 -> Tabularisation
    // int n = nums.size();
    // return soveTab(nums, n);

    // 4 -> Tabularisation with Space Optimisation
    int n = nums.size();
    return soveTabSO(nums, n);
}

int main() {
    vector<int> arr = {2, 3, 4, 1, 5, 6, 8};
    cout << "The maximum sum of non adjacent elements in the array: " << maximumNonAdjacentSum(arr) << endl;
    return 0;
}