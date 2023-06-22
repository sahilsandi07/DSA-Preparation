#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;

long long int solveRec(int n) {
    // base case
    if (n == 1) return 0;
    if (n == 2) return 1;

    return (((n-1)%MOD)*((solveRec(n-1)%MOD) + (solveRec(n-2)%MOD)) % MOD);
}

long long int solveMem(int n, vector<long long int> &dp) {
    // base case
    if (n == 1) return 0;
    if (n == 2) return 1;

    if (dp[n] != -1) return dp[n];

    return dp[n] = (((n-1)%MOD)*((solveMem(n-1, dp)%MOD) + (solveMem(n-2, dp)%MOD)) % MOD);
}

long long int solveTab(int n) {

    vector<long long int> dp(n+1, 0);
    // base case
    dp[1] = 0;
    dp[2] = 1;

    for (int i=3; i<=n; i++) {
        long long int first = dp[i-1] % MOD;
        long long int second = dp[i-2] % MOD;

        dp[i] = ((i-1)*(first + second)) % MOD;
    }

    return dp[n];
}

long long int countDerangements(int n) {
    // 1 -> Recursion
    // return solveRec(n);

    // 2 -> Memoization
    // vector<long long int> dp(n+1, -1);
    // return solveMem(n, dp);

    // 3 -> Tabularisation
    return solveTab(n);
}