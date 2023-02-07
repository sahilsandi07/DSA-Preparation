//User function Template for C++

class Solution{
    public:
        long long sumUnderModulo(long long a,long long b)
    {
        // code here
        const int MOD = 1e9 + 7;
        return ( (a % MOD + b % MOD) % MOD + MOD ) % MOD;
    }
};