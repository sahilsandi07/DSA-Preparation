class Solution {
private:
    int solveRec (int n, int m, string &s1, string &s2) {
        if (n < 0 || m < 0) {
            return 0;
        }

        // if the character matches
        if (s1[n] == s2[m]) {
            return 1 + solveRec (n-1, m-1, s1, s2);
        }
        
        return max (solveRec(n-1, m, s1, s2), solveRec(n, m-1, s1, s2));        
    }

    int solveMem (int n, int m, string &s1, string &s2, vector<vector<int>>&dp) {
        if (n < 0 || m < 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        // if the character matches
        if (s1[n] == s2[m]) {
            return dp[n][m] = 1 + solveMem (n-1, m-1, s1, s2, dp);
        }
        
        return dp[n][m] = max (solveMem(n-1, m, s1, s2, dp), solveMem(n, m-1, s1, s2, dp));        
    }

    int solveTab(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // if the characters match
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }


public:
    int longestCommonSubsequence(string text1, string text2) {
        // 1 -> Recursion
        // int n = text1.size();
        // int m = text2.size();
        // return solveRec(n-1, m-1, text1, text2);

        // 2 -> Memoization
        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>> dp (n+1, vector<int> (m+1, -1));
        // return solveMem(n-1, m-1, text1, text2, dp);

        // 3 -> Tabulation with space optimisation
        int n = text1.size();
        int m = text2.size();
        vector<int> curr (m+1, 0);
        vector<int> prev (m+1, 0);

        for (int i=1 ;i<=n; i++) {
            for (int j=1; j<=m; j++) {
                // if the character matches
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j-1];
                }
                
                else curr[j] = max (prev[j], curr[j-1]);
            }

            prev = curr;
        }

        return prev[m];
    }
};