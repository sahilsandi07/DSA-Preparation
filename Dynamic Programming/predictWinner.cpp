class Solution {
private:
    int solveRec(vector<int>& nums, int left, int right, int n) {
        if (left == right) {
            return nums[left];
        }

        int scoreByLeft = nums[left] - solveRec(nums, left + 1, right, n);
        int scoreByRight = nums[right] - solveRec(nums, left, right - 1, n);

        return (scoreByLeft > scoreByRight) ? scoreByLeft : scoreByRight;
    }

    int solveMem(vector<int>& nums, int left, int right, int n, vector<vector<int>> &dp) {
        if (left == right) {
            return nums[left];
        }

        if (dp[left][right] != -1) return dp[left][right];

        int scoreByLeft = nums[left] - solveMem(nums, left + 1, right, n, dp);
        int scoreByRight = nums[right] - solveMem(nums, left, right - 1, n, dp);

        return dp[left][right] = (scoreByLeft > scoreByRight) ? scoreByLeft : scoreByRight;
    }

    bool solveTab (vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] >= 0;
    }

public:
    bool PredictTheWinner(vector<int>& nums) {
        // 1 -> Recursion
        // int n = nums.size();
        // return solveRec(nums, 0, n - 1, n) >= 0;

        // 2 -> Memoization
        // int n = nums.size();
        // vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        // return solveMem(nums, 0, n-1, n, dp) >= 0;

        // 3 -> Tabulation
        return solveTab(nums);
    }
};