//User function Template for C++

class Solution{
    public:
        int multiplicationUnderModulo(long long a,long long b)
    {
        //your code here
        const int MOD = 1e9 + 7;
        a = (a % MOD + MOD) % MOD;
        b = (b % MOD + MOD) % MOD;
        return ( (a * b) % MOD + MOD ) % MOD;
    }
};