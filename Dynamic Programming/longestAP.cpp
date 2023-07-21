class Solution {
private:
    int solveRec (int index, int diff, int A[]) {
        if (index < 0) {
            return 0;
        }
        
        int ans = 0;
        for (int j = index - 1; j >= 0; j--) {
            if (A[index] - A[j] == diff) {
                ans = max (ans, 1 + solveRec (j, diff, A));
            }
        }
        
        return ans;
    }
    
    int solveMem (int index, int diff, int A[], unordered_map<int,int> dp[]) {
        if (index < 0) {
            return 0;
        }
        
        if (dp[index].count(diff)) {
            return dp[index][diff];
        }
        
        int ans = 0;
        for (int j = index - 1; j >= 0; j--) {
            if (A[index] - A[j] == diff) {
                ans = max (ans, 1 + solveMem (j, diff, A, dp));
            }
        }
        
        return dp[index][diff] = ans;
    }
    
public:
    int lengthOfLongestAP(int A[], int n) {
        // 1 -> Recursion
        // if (n <= 2) {
        //     return n;
        // }
        
        // int ans = 0;
        
        // for (int i=0; i<n; i++) {
        //     for (int j=1+1; j<n; j++) {
        //         ans = max (ans, 2 + solveRec (i, A[j]-A[i], A));
        //     }
        // }
        
        // return ans;
        
        // 2 -> Memoization (DP with Hashing)
        // if (n <= 2) {
        //     return n;
        // }
        
        // int ans = 0;
        
        // unordered_map<int, int> dp[n+1];
        // for (int i=0; i<n; i++) {
        //     for (int j=1+1; j<n; j++) {
        //         ans = max (ans, 2 + solveMem (i, A[j]-A[i], A, dp));
        //     }
        // }
        
        // return ans;
        
        // 3 -> Optimal Solution
        if (n <= 2)
            return n;
        
        int maxLength = 2;  
        vector<vector<int>> dp(n, vector<int>(n, 2)); 
        
        for (int i = 0; i < n; i++) {
            int j = i - 1, k = i + 1;
            while (j >= 0 && k < n) {
                if (A[j] + A[k] == 2 * A[i]) {
                    dp[i][k] = dp[j][i] + 1; 
                    maxLength = max(maxLength, dp[i][k]);
                    j--; 
                    k++; 
                } else if (A[j] + A[k] < 2 * A[i]) {
                    k++;
                } else {
                    j--;
                }
            }
        }
        
        return maxLength;
    }
};