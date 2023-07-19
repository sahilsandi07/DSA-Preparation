#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool solveRec (int index, int n, int arr[], int target) {
        // base case
        if (index >= n || target < 0) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }
        
        bool include = solveRec (index + 1, n, arr, target - arr[index]);
        bool exclude = solveRec (index + 1, n, arr, target);
        
        return include or exclude;
    }
    
    bool solveMem (int index, int n, int arr[], int target, vector<vector<int>> &dp) {
        // base case
        if (index >= n || target < 0) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }
        
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        
        bool include = solveMem (index + 1, n, arr, target - arr[index], dp);
        bool exclude = solveMem (index + 1, n, arr, target, dp);
        
        return dp[index][target] = include or exclude;
    }
    
    bool solveTab (int n, int arr[], int total) {
        vector<vector<int>> dp (n+1, vector<int> (total + 1, 0));
        
        for (int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }
        
        for (int index = n-1; index >= 0; index--) {
            for (int target = 0; target <= total/2; target++) {
                bool include = 0;
                if (target - arr[index] >= 0) {
                    include = dp[index + 1][target - arr[index]];
                }
                bool exclude = dp[index + 1][target];
                
                dp[index][target] = include or exclude;
            }
        }
        
        return dp[0][total/2];
    }
    
    bool solveTabSO (int n, int arr[], int total) {
        vector<int> curr (total + 1, 0);
        vector<int> next (total + 1, 0);

        curr[0] = 1;
        next[0] = 1;
        
        for (int index = n-1; index >= 0; index--) {
            for (int target = 0; target <= total/2; target++) {
                bool include = 0;
                if (target - arr[index] >= 0) {
                    include = next[target - arr[index]];
                }
                bool exclude = next[target];
                
                curr[target] = include or exclude;
            }
            
            next = curr;
        }
        
        return next[total/2];
    }
    
public:
    int equalPartition(int N, int arr[]) {
        // 1 -> Recursion
        // int totalSum = 0;
        // for (int i=0; i<N; i++) {
        //     totalSum += arr[i];
        // }
        
        // if (totalSum & 1) {
        //     return 0;
        // }
        
        // int target = totalSum/2;
        
        // return solveRec (0, N, arr, target);
        
        // 2 -> Memoization
        // int totalSum = 0;
        // for (int i=0; i<N; i++) {
        //     totalSum += arr[i];
        // }
        
        // if (totalSum & 1) {
        //     return 0;
        // }
        
        // int target = totalSum/2;
        
        // vector<vector<int>> dp (N, vector<int> (target + 1, -1));
        
        // return solveMem (0, N, arr, target, dp);
        
        // 3 -> Tabulation
        // int totalSum = 0;
        // for (int i=0; i<N; i++) {
        //     totalSum += arr[i];
        // }
        
        // if (totalSum & 1) {
        //     return 0;
        // }
        
        // return solveTab (N, arr, totalSum);
        
        // 4 -> Space Optimisation
        int totalSum = 0;
        for (int i=0; i<N; i++) {
            totalSum += arr[i];
        }
        
        if (totalSum & 1) {
            return 0;
        }
        
        return solveTabSO (N, arr, totalSum);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}