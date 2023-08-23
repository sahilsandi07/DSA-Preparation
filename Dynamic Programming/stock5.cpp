class Solution {
private:    
    int solveRec (vector<int>& prices, int n, int index, bool buy) {
        if (index >= n) {
            return 0;
        }

        if (buy) {
            return max ((-prices[index] + solveRec (prices, n, index + 1, 0)),
            (0 + solveRec (prices, n, index + 1, 1)));
        }
        else {
            return max ((prices[index] + solveRec (prices, n, index + 2, 1)),
            (0 + solveRec (prices, n, index + 1, 0)));
        }
    }
    int solveMem (vector<int>& prices, int n, int index, int buy, vector<vector<int>> &dp) {
        if (index >= n) {
            return 0;
        }

        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }

        if (buy == 1) {
            return dp[index][buy] = max ((-prices[index] + solveMem (prices, n, index + 1, 0, dp)),
            (0 + solveMem (prices, n, index + 1, 1, dp)));
        }
        else {
            return dp[index][buy] = max ((prices[index] + solveMem (prices, n, index + 2, 1, dp)),
            (0 + solveMem (prices, n, index + 1, 0, dp)));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // return solveRec (prices, n, 0, true);
        vector<vector<int>> dp (n+2, vector<int>  (3, -1));
        return solveMem (prices, n, 0, 1, dp);
    }
};