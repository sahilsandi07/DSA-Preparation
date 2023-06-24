#include <bits/stdc++.h> 
using namespace std;

int solveRec(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
	// base case
	if (n == 0) {
		if (weight[0] <= maxWeight) {
			return value[0];
		}
		else {
			return 0;
		}
	}

	int include = 0;
	if (weight[n] <= maxWeight) {
		include = value[n] + solveRec (weight, value, n-1, maxWeight - weight[n]);
	}
	int exclude = 0 + solveRec (weight, value, n-1, maxWeight);

	return max (include, exclude);
}

int solveMem(vector<int> &weight, vector<int> &value, int n, int maxWeight,
vector<vector<int>> &dp) {
	// base case
	if (n == 0) {
		if (weight[0] <= maxWeight) {
			return value[0];
		}
		else {
			return 0;
		}
	}

	if (dp[n][maxWeight] != -1) return dp[n][maxWeight];

	int include = 0;
	if (weight[n] <= maxWeight) {
		include = value[n] + solveMem (weight, value, n-1, maxWeight - weight[n], dp);
	}
	int exclude = 0 + solveMem (weight, value, n-1, maxWeight, dp);

	return dp[n][maxWeight] = max (include, exclude);
}

int solveTab(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

	for (int w = weight[0]; w <= maxWeight; w++) {
		if (w <= maxWeight) {
			dp[0][w] = value[0];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= maxWeight; j++) {
			int include = 0;
			if (weight[i] <= j) {
				include = value[i] + dp[i - 1][j - weight[i]];
			}
			int exclude = dp[i - 1][j];

			dp[i][j] = max(include, exclude);
		}
	}

	return dp[n - 1][maxWeight];
}

int solveTabSO(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
	//vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
	vector<int> prev (maxWeight + 1, 0);
	vector<int> curr (maxWeight + 1, 0);

	for (int w = weight[0]; w <= maxWeight; w++) {
		if (w <= maxWeight) {
			prev[w] = value[0];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= maxWeight; j++) {
			int include = 0;
			if (weight[i] <= j) {
				include = value[i] + prev[j - weight[i]];
			}
			int exclude = prev[j];

			curr[j] = max(include, exclude);
		}
		prev = curr;
	}

	return prev[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// 1 -> Recursion
	// return solveRec (weight, value, n-1, maxWeight);

	// 2 -> 2D DP memoization
	// here while doing recursion calls two states are changing,
	// the current index and the maxWeight. Hence we use 2d DP
	// vector<vector<int>> dp (n, vector<int> (maxWeight + 1, -1));
	// return solveMem (weight, value, n-1, maxWeight, dp);

	// 3 -> Tabularisation
	// return solveTab (weight, value, n, maxWeight);

	// 4 -> Space Optimisation
	return solveTabSO (weight, value, n, maxWeight);
}