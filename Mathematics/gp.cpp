//User function Template for C++

class Solution{
    public:
        //Complete this function
    double termOfGP(int A,int B,int N)
    {
        double r, An;
        // Calculate common ratio
        r = (double) B/A;
        // Calculate Nth term
        An = A * pow(r, N-1);
        return An;
    }
};