#include <bits/stdc++.h>

using namespace std;

long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp ){

    if(ind==n) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    long profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind] + getAns(Arr,ind+1,1,n,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind] + getAns(Arr,ind+1,0,n,dp));
    }
    
    return dp[ind][buy] = profit;
}


long getMaximumProfit(long *Arr, int n)
{
    //Write your code here
    
    vector<vector<long>> dp(n,vector<long>(2,-1));
    
    if(n==0) return 0;
    long ans = getAns(Arr,0,0,n,dp);
    return ans;
}

int main() {

  int n =6;
  long Arr[n] = {7,1,5,3,6,4};
                                 
  cout<<"The maximum profit that can be generated is "<<getMaximumProfit(Arr, n);
}