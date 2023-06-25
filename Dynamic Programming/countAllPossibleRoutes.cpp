#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution {
private:
    int solveRec(vector<int>& locations, int start, int finish, int fuel) {
        // Base Case
        if (fuel < 0) {
            return 0;
        }

        // if at any moment we reach finish, we have found our route
        int routes = 0;
        if (start == finish) routes++;

        for (int i = 0; i < locations.size(); i++) {
            if (i == start || abs(locations[i] - locations[start]) > fuel) continue;
            int newFuel = fuel - abs(locations[i] - locations[start]);
            routes += solveRec(locations, i, finish, newFuel);
            routes %= MOD;
        }

        return routes % MOD;
    }

    int solveMem(vector<int>& locations, int start, int finish, int fuel,
                 vector<vector<int>>& dp) {
        // Base Case
        if (fuel < 0) {
            return 0;
        }

        if (dp[start][fuel] != -1) return dp[start][fuel];

        // if at any moment we reach finish, we have found our route
        int routes = 0;
        if (start == finish) routes++;

        for (int i = 0; i < locations.size(); i++) {
            if (i == start || abs(locations[i] - locations[start]) > fuel) continue;
            int newFuel = fuel - abs(locations[i] - locations[start]);
            routes += solveMem(locations, i, finish, newFuel, dp);
            routes %= MOD;
        }

        return dp[start][fuel] = routes %= MOD;
    }

    int solveTab(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));
        
        dp[start][fuel] = 1; // There is 1 way to reach the finish from the start with given fuel
        
        for (int f = fuel; f >= 0; f--) {
            for (int i = 0; i < n; i++) {
                if (dp[i][f] == 0) // No valid route from location i with fuel f
                    continue;
                
                for (int j = 0; j < n; j++) {
                    if (i == j) // Cannot go to the same location
                        continue;
                    
                    int fuelNeeded = abs(locations[i] - locations[j]);
                    if (fuelNeeded <= f) {
                        dp[j][f - fuelNeeded] += dp[i][f]; // Accumulate the number of ways
                        dp[j][f - fuelNeeded] %= MOD;
                    }
                }
            }
        }
        
        int totalRoutes = 0;
        for (int f = 0; f <= fuel; f++) {
            totalRoutes += dp[finish][f];
            totalRoutes %= MOD;
        }
        
        return totalRoutes;
    }

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // 1 -> Recursion
        // return solveRec(locations, start, finish, fuel);

        // 2 -> Memoization
        // int sz = locations.size();
        // vector<vector<int>> dp(sz, vector<int>(fuel + 1, -1));
        // return solveMem(locations, start, finish, fuel, dp);

        // 3 -> Tabularization
        return solveTab(locations, start, finish, fuel);
    }
};
