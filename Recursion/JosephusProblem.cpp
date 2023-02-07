/*You are required to complete this method */

class Solution
{
    public:
    int josephus(int n, int k)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            res = (res + k) % i;
        return res + 1;   
    }
};
