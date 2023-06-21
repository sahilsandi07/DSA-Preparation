#include<bits/stdc++.h>
using namespace std;

int solveRec(int n, int x, int y, int z) {
	if (n == 0) {
		return 0;
	}

	if (n < 0) {
		return INT_MIN;
	}

	int first_way = solveRec(n-x, x, y, z) + 1;
	int second_way = solveRec(n-y, x, y, z) + 1;
	int third_way = solveRec(n-z, x, y, z) + 1;

	return max (first_way, max(second_way, third_way));
}

int solveMem(int n, int x, int y, int z, vector<int> &dp) {
	if (n == 0) {
		return 0;
	}

	if (n < 0) {
		return INT_MIN;
	}

	if (dp[n] != -1) return dp[n];

	int first_way = solveMem(n-x, x, y, z, dp) + 1;
	int second_way = solveMem(n-y, x, y, z, dp) + 1;
	int third_way = solveMem(n-z, x, y, z, dp) + 1;

	return dp[n] = max (first_way, max(second_way, third_way));
}

int solveTab(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);
	dp[0] = 0;

	for (int i=1; i<=n; i++) {
		if (i-x >= 0 && dp[i-x] != -1)
			dp[i] = max(dp[i], dp[i-x] + 1);

		if (i-y >= 0 && dp[i-y] != -1)
			dp[i] = max(dp[i], dp[i-y] + 1);

		if (i-z >= 0 && dp[i-z] != -1)
			dp[i] = max(dp[i], dp[i-z] + 1);
	}

	if (dp[n] < 0) return 0;
	else return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// 1 -> Recursion
	// int ans = solveRec(n, x, y, z);
	// if (ans < 0) {
	// 	return 0;
	// }
	// else return ans;

	// 2 -> Memoization
	// vector<int> dp(n+1, -1);
	// int ans = solveMem(n, x, y, z, dp);
	// if (ans < 0) {
	// 	return 0;
	// }
	// else return ans;

	// 3 -> Memoization
	return solveTab(n, x, y, z);
}

int main() {
    int n = 10;
    int x = 2;
    int y = 4;
    int z = 4;

    cout << "Answer is: " << cutSegments(n, x, y, z) << endl;

    return 0;
}