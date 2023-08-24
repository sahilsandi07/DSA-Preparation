int solveRec (vector<int>& prices, int n, int index, bool buy, int fee) {

    if (index == n) {
        return 0;
    }

    if (buy) {
        return max ((-prices[index] + solveRec (prices, n, index + 1, 0, fee)),
        (0 + solveRec (prices, n, index + 1, 1, fee)));
    }
    else {
        return max ((prices[index] - fee + solveRec (prices, n, index + 1, 1, fee)),
        (0 + solveRec (prices, n, index + 1, 0, fee)));
    }
}

int solveMem (vector<int>& prices, int n, int index, int buy, int fee,
              vector<vector<int>> &dp) {

    if (index == n) {
        return 0;
    }

    if (dp[index][buy] != -1) {
        return dp[index][buy];
    }

    if (buy == 1) {
        return dp[index][buy] = max ((-prices[index] + solveMem (prices, n, index + 1, 0, fee, dp)),
        (0 + solveMem (prices, n, index + 1, 1, fee, dp)));
    }
    else {
        return dp[index][buy] = max ((prices[index] - fee + solveMem (prices, n, index + 1, 1, fee, dp)),
        (0 + solveMem (prices, n, index + 1, 0, fee, dp)));
    }
}
int maximumProfit(vector<int> &prices, int n, int fee)
{
	// Write your code here.
	// return solveRec(prices, n, 0, 1, fee);
	vector<vector<int>> dp(n+1, vector<int>(3, -1));
    return solveMem (prices, n, 0, 1, fee, dp);

}
