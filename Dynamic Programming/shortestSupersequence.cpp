#include <bits/stdc++.h> 
using namespace std;
string shortestSupersequence(string text1, string text2)
{
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

	string shortestSupersequence = "";
	int i = n;
	int j = m;

	while (i > 0 && j > 0) {
		if (text1[i-1] == text2[j-1]) {
			shortestSupersequence += text1[i-1];
			i--;
			j--;
		}

		else if (dp[i-1][j] > dp[i][j-1]) {
			shortestSupersequence += text1[i-1];
			i--;
		}

		else {
			shortestSupersequence += text2[j-1];
			j--;
		}
	}

	while (i > 0) {
		shortestSupersequence += text1[i - 1];
		i--;
	}

	while (j > 0) {
		shortestSupersequence += text2[j - 1];
		j--;
	}

	reverse (shortestSupersequence.begin(), shortestSupersequence.end());

	return shortestSupersequence;
}