class Solution {
private:
    int solveRec(int index, int endIndex, vector<int>& slices, int n) {
        if (n == 0 || index > endIndex) {
            return 0;
        }

        int eatSlice = slices[index] + solveRec(index + 2, endIndex, slices, n - 1);
        int skipSlice = solveRec(index + 1, endIndex, slices, n);

        return max(eatSlice, skipSlice);
    }

    int solveMem(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp) {
        if (n == 0 || index > endIndex) {
            return 0;
        }

        if (dp[n][index] != -1) {
            return dp[n][index];
        }

        int eatSlice = slices[index] + solveMem(index + 2, endIndex, slices, n - 1, dp);
        int skipSlice = solveMem(index + 1, endIndex, slices, n, dp);

        return dp[n][index] = max(eatSlice, skipSlice);
    }

    int solveTab(vector<int>& slices, int n) {
        int k = slices.size();
        vector<vector<int>> dp1(n + 1, vector<int>(k + 1, 0)); // DP table excluding the first element
        vector<vector<int>> dp2(n + 1, vector<int>(k + 1, 0)); // DP table excluding the last element

        // Calculate dp1 (excluding the first element)
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k - 1; ++j) { // k - 1, as we are excluding the first element
                dp1[i][j] = max((j >= 2 ? dp1[i - 1][j - 2] : 0) + slices[j - 1], dp1[i][j - 1]);
            }
        }

        // Calculate dp2 (excluding the last element)
        for (int i = 1; i <= n; ++i) {
            for (int j = 2; j <= k; ++j) { // Starting from index 2 to exclude the last element
                dp2[i][j] = max((j >= 3 ? dp2[i - 1][j - 2] : 0) + slices[j - 1], dp2[i][j - 1]);
            }
        }

        return max(dp1[n][k - 1], dp2[n][k]);
    }

    int solveTabSO(vector<int>& slices, int n) {
        int k = slices.size();
        vector<int> dp1(k + 1, 0); // DP array excluding the first element
        vector<int> dp2(k + 1, 0); // DP array excluding the last element

        // Calculate dp1 (excluding the first element)
        for (int i = 1; i <= n; ++i) {
            vector<int> next(k + 1, 0);
            for (int j = 1; j <= k - 1; ++j) { // k - 1, as we are excluding the first element
                next[j] = max((j >= 2 ? dp1[j - 2] : 0) + slices[j - 1], next[j - 1]);
            }
            dp1 = next;
        }

        // Calculate dp2 (excluding the last element)
        for (int i = 1; i <= n; ++i) {
            vector<int> next(k + 1, 0);
            for (int j = 2; j <= k; ++j) { // Starting from index 2 to exclude the last element
                next[j] = max((j >= 3 ? dp2[j - 2] : 0) + slices[j - 1], next[j - 1]);
            }
            dp2 = next;
        }

        return max(dp1[k - 1], dp2[k]);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        // 1 -> Recursion
        // int k = slices.size();
        // int case1 = solveRec(0, k - 2, slices, k / 3);
        // int case2 = solveRec(1, k - 1, slices, k / 3);
        // return max(case1, case2);

        // 2 -> Memoization
        // int k = slices.size();
        // int n = k / 3;
        // vector<vector<int>> dp1(k, vector<int>(k, -1));
        // int case1 = solveMem(0, k - 2, slices, k / 3, dp1);

        // vector<vector<int>> dp2(k, vector<int>(k, -1));
        // int case2 = solveMem(1, k - 1, slices, k / 3, dp2);

        // return max(case1, case2);

        // 3 -> Tabulation
        // int k = slices.size();
        // int n = k / 3;
        // return solveTab(slices, n);

        // 4 -> Space Optimisation
        int k = slices.size();
        int n = k / 3;
        return solveTabSO(slices, n);
    }
};
