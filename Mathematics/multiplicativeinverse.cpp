//User function Template for C++

class Solution{
    public:
    int gcdExtended(int a, int b, int *x, int *y)
    {
        if (a == 0)
        {
            *x = 0;
            *y = 1;
            return b;
        }
        int x1, y1;
        int gcd = gcdExtended(b % a, a, &x1, &y1);
        *x = y1 - (b / a) * x1;
        *y = x1;
        return gcd;
    }
    
    int modInverse(int a, int m)
    {
        if (m == 1)
            return -1;
        int x, y;
        int g = gcdExtended(a, m, &x, &y);
        if (g != 1)
        {
            return -1;
        }
        else
        {
            int res = (x % m + m) % m;
            return res;
        }
    }
};