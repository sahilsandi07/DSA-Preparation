//User function Template for C++

class Solution{
    public:
    int digitsInFactorial(int N)
    {
        if (N == 0) {
            return 1;
        }
        double digits = 0;
        for (int i = 1; i <= N; i++) {
            digits += log10(i);
        }
        return (int)floor(digits) + 1;
    }
};