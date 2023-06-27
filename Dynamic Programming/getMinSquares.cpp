#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int solveRec (int n) {
        // base case
        if (n == 0) return 0;
        
        int ans = n;
        for (int i=1; i*i <= n; i++) {
            int temp = i*i;
            ans = min (ans, 1 + solveRec(n-temp));
        }
        
        return ans;
    }
    
    int solveMem (int n, vector<int> &dp) {
        // base case
        if (n == 0) return 0;
        
        // check for  overlapping sub problems
        if (dp[n] != -1) return dp[n];
        
        int ans = n;
        for (int i=1; i*i <= n; i++) {
            int temp = i*i;
            ans = min (ans, 1 + solveMem(n-temp, dp));
        }
        
        return dp[n] = ans;
    }
    
    int solveTab (int n) {
        
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j*j <= n; j++) {
                int temp = j*j;
                if (i-temp >= 0)
                    dp[i] = min (dp[i], 1 + dp[i - temp]);
            }
        }
        
        return dp[n];
    }
    
	public:
	int MinSquares(int n) {
	    // 1 -> Recursion
	    // return solveRec(n);
	    
	    // 2 -> Memoization
	    // vector<int> dp(n+1, -1);
	    // return solveMem (n, dp);
	   
	    // 3 -> Tabulation
	   return solveTab (n);
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}