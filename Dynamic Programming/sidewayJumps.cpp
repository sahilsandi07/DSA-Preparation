class Solution {
    private:
    int solveRec (vector<int>& obstacles, int currLane, int currPos) {
        int n = obstacles.size() - 1;
        if (currPos == n) return 0;

        if (obstacles[currPos + 1] != currLane) {
            return solveRec (obstacles, currLane, currPos + 1);
        }

        else {
            int ans = INT_MAX;
            for (int i=1; i<=3; i++) {
                if (currLane != i && obstacles[currPos] != i) {
                    ans = min (ans, 1 + solveRec(obstacles, i, currPos));
                }
            }
            return ans;
        }
    }

    int solveMem(vector<int>& obstacles, int currLane, int currPos, vector<vector<int>>& dp) {
        int n = obstacles.size() - 1;
        if (currPos == n) return 0;

        if (dp[currLane][currPos] != -1) return dp[currLane][currPos];

        if (obstacles[currPos + 1] != currLane) {
            return solveMem (obstacles, currLane, currPos + 1, dp);
        }

        else {
            int ans = INT_MAX;
            for (int i=1; i<=3; i++) {
                if (currLane != i && obstacles[currPos] != i) {
                    ans = min (ans, 1 + solveMem(obstacles, i, currPos, dp));
                }
            }
            return dp[currLane][currPos] = ans;
        }
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        // 1 -> Recursion
        // return solveRec (obstacles, 2, 0);

        // 2 -> Memoization
        int n = obstacles.size();
        vector<vector<int>> dp (4, vector<int> (n + 1, -1));
        return solveMem (obstacles, 2, 0, dp);
    }
};