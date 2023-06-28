class Solution {
private:
    int solveRec(int n, vector<int>& days, vector<int>& cost, int index) {
        // Base case: if all days have been covered
        if (index >= n) {
            return 0;
        }

        // Check if we can buy a one-day ticket
        int oneDayTicket = cost[0] + solveRec(n, days, cost, index + 1);

        // Find the next eligible day for a 7-day ticket
        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++);

        // Check if we can buy a seven-day ticket
        int sevenDaysTicket = cost[1] + solveRec(n, days, cost, i);

        // Find the next eligible day for a 30-day ticket
        for (i = index; i < n && days[i] < days[index] + 30; i++);

        // Check if we can buy a thirty-day ticket
        int thirtyDaysTicket = cost[2] + solveRec(n, days, cost, i);

        // Return the minimum cost among the available ticket options
        return min(oneDayTicket, min(sevenDaysTicket, thirtyDaysTicket));
    }

    int solveMem(int n, vector<int>& days, vector<int>& cost, int index,
    vector<int> &dp) {
        // Base case: if all days have been covered
        if (index >= n) {
            return 0;
        }

        if (dp[index] != -1) return dp[index];

        // Check if we can buy a one-day ticket
        int oneDayTicket = cost[0] + solveMem(n, days, cost, index + 1, dp);

        // Find the next eligible day for a 7-day ticket
        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++);

        // Check if we can buy a seven-day ticket
        int sevenDaysTicket = cost[1] + solveMem(n, days, cost, i, dp);

        // Find the next eligible day for a 30-day ticket
        for (i = index; i < n && days[i] < days[index] + 30; i++);

        // Check if we can buy a thirty-day ticket
        int thirtyDaysTicket = cost[2] + solveMem(n, days, cost, i, dp);

        // Return the minimum cost among the available ticket options
        return dp[index] = min(oneDayTicket, min(sevenDaysTicket, thirtyDaysTicket));
    }

    int solveTab(int n, vector<int>& days, vector<int>& cost, int index) {
        vector<int> dp (n+1, INT_MAX);
        dp[n] = 0;

        for (int k=n-1; k>=0; k--) {
            // Check if we can buy a one-day ticket
            int oneDayTicket = cost[0] + dp[k + 1];

            // Find the next eligible day for a 7-day ticket
            int i;
            for (i = k; i < n && days[i] < days[k] + 7; i++);

            // Check if we can buy a seven-day ticket
            int sevenDaysTicket = cost[1] + dp[i];

            // Find the next eligible day for a 30-day ticket
            for (i = k; i < n && days[i] < days[k] + 30; i++);

            // Check if we can buy a thirty-day ticket
            int thirtyDaysTicket = cost[2] + dp[i];

            // Return the minimum cost among the available ticket options
            return dp[k] = min(oneDayTicket, min(sevenDaysTicket, thirtyDaysTicket));
        }

        return dp[0];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        // 1 -> Recursion
        // int n = days.size();
        // int index = 0;
        // return solveRec(n, days, cost, index);

        // 2 -> Memoization
        // Best Solution
        int n = days.size();
        int index = 0;
        vector<int> dp (n+1, -1);
        return solveMem (n, days, cost, index, dp);

        // 3 -> Tabulation
        // int n = days.size();
        // int index = 0;
        // return solveRec(n, days, cost, index);

    }
};
