class Solution {
private:
    int solveRec (vector<int>& satisfaction, int index, int time) {
        if (index == satisfaction.size()) {
            return 0;
        }
        int includeDish = satisfaction[index]*(time + 1) + solveRec(satisfaction, index + 1, time + 1);
        int discardDish = 0 + solveRec (satisfaction, index + 1, time);

        return max (includeDish, discardDish);
    }

    int solveMem (vector<int>& satisfaction, int index, int time, vector<vector<int>> &dp) {
        if (index == satisfaction.size()) {
            return 0;
        }

        if (dp[index][time] != -1) return dp[index][time];

        int includeDish = satisfaction[index]*(time + 1) + solveMem(satisfaction, index + 1, time + 1, dp);
        int discardDish = 0 + solveMem (satisfaction, index + 1, time, dp);

        return dp[index][time] = max (includeDish, discardDish);
    }

    int solveTab (vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp (n+1, vector<int> (n+1, 0));

        for (int index=n-1; index>=0; index--) {
            for (int time = index; time>=0; time--) {
                int includeDish = satisfaction[index]*(time + 1) + dp[index + 1][time + 1];
                int discardDish = dp[index + 1][time];
                dp[index][time] = max (includeDish, discardDish);
            }            
        }
        return dp[0][0];
    }

    int solveTabSO (vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<int> curr (n+1, 0);
        vector<int> next (n+1, 0);

        for (int index=n-1; index>=0; index--) {
            for (int time = index; time>=0; time--) {
                int includeDish = satisfaction[index]*(time + 1) + next[time + 1];
                int discardDish = next[time];
                curr[time] = max (includeDish, discardDish);
            }  
            next = curr;          
        }
        return next[0];
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // 1 -> Recursion
        // sort(satisfaction.begin(), satisfaction.end()); // Sort the satisfaction values
        // int index = 0;
        // int time = 0;
        // return solveRec(satisfaction, index, time);

        // 2 -> Memoization
        // sort(satisfaction.begin(), satisfaction.end());
        // int n = satisfaction.size();
        // int index = 0;
        // int time = 0;
        // vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        // return solveMem (satisfaction, index, time, dp);

        // 3 -> Tabulation
        // sort(satisfaction.begin(), satisfaction.end());
        // return solveTab (satisfaction);

        // 4 -> Space Optimisation
        sort(satisfaction.begin(), satisfaction.end());
        return solveTabSO (satisfaction);
    }
};