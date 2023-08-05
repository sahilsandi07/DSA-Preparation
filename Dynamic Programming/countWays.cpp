#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(int n, int minPart, vector<vector<int>> &dp)
    {
        if (n == 0)
            return 1;
        
        if (n < 0)
            return 0; 
            
        if (dp[n][minPart] != -1) return dp[n][minPart];

        int ways = 0;
        
        for (int i = minPart; i <= n; ++i)
        {
            ways = (ways + countWays(n - i, i, dp)) % (1000000007); 
        }
        
        return dp[n][minPart] = ways;
    }
    
    // Wrapper function to initialize the recursion with minPart = 1.
    int countWays(int n)
    {
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        return countWays(n, 1, dp) - 1;
    }
};

int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.countWays(n)<<endl;
    }
    return 0;
}