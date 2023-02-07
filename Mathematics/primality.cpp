//User function Template for C++

class Solution{
    public:
        bool isPrime(int N)
    {
        if (N < 2) {
            return false;
        }
        for (int i = 2; i <= sqrt(N); i++) {
            if (N % i == 0) {
                return false;
            }
        }
        return true;
    }

};