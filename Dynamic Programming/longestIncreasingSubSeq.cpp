#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solveRec (int n, int a[], int curr, int prev) {
        // base case
        if (curr == n) {
            return 0;
        }
        
        // include the curret element
        int includeElement = 0;
        if (prev == -1 || a[prev] < a[curr]) {
            includeElement = 1 + solveRec (n, a, curr + 1, curr);
        }
        
        // exclude element
        int excludeElement = solveRec (n, a, curr + 1, prev);
        
        return max(includeElement, excludeElement);
    }
    
    int solveMem (int n, int a[], int curr, int prev, vector<vector<int>> &dp) {
        // base case
        if (curr == n) {
            return 0;
        }
        
        if (dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }
        
        // include the curret element
        int includeElement = 0;
        if (prev == -1 || a[prev] < a[curr]) {
            includeElement = 1 + solveMem (n, a, curr + 1, curr, dp);
        }
        
        // exclude element
        int excludeElement = solveMem (n, a, curr + 1, prev, dp);
        
        return dp[curr][prev+1] = max(includeElement, excludeElement);
    }
    
    int solveTab (int n, int a[]) {
        vector<vector<int>> dp (n+1, vector<int> (n+1, 0));
        
        for (int curr = n-1; curr >= 0; curr--) {
            for (int prev = curr-1; prev >= -1; prev--) {
                // include the curret element
                int includeElement = 0;
                if (prev == -1 || a[prev] < a[curr]) {
                    includeElement = 1 + dp[curr + 1][curr + 1];
                }
                
                // exclude element
                int excludeElement = dp[curr + 1][prev + 1];
                
                dp[curr][prev+1] = max(includeElement, excludeElement);
            }
        }
        
        return dp[0][0];
    }
    
    int optimalSolution (int n, int a[]) {
        if (n == 0) {
            return 0;
        }
        vector<int> ans;
        ans.push_back(a[0]);
        
        for (int i=1; i<n; i++) {
            if (a[i] > ans.back()) {
                ans.push_back(a[i]);
            }
            else {
                int index = lower_bound (ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        
        return ans.size();
    }
    
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // 1 -> Recursion
       //   int curr = 0;
       //   int prev = -1;
       //   return solveRec (n, a, curr, prev);
       
       // 2 -> Memoization
       //   int curr = 0;
       //   int prev = -1;
       //   vector<vector<int>> dp (n, vector<int> (n+1, -1));
       //   return solveMem (n, a, curr, prev, dp);
       
       // 3 -> Tabulation
       // return solveTab(n, a);
       
       // 4 -> Optimal
       return optimalSolution (n, a);
    }
};

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}