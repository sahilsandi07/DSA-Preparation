#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(int n) {
        int mod = 1e9 + 7;
        if (n <= 1) {
            return 1;
        }
       
        long long prev = 1;
        long long current = 1;
        long long ways = 0;
        
        for (int i = 2; i <= n; i++) {
            ways = (prev + current) % mod;
            prev = current;
            current = ways;
        }
        return static_cast<int>(ways);
    }
};

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
