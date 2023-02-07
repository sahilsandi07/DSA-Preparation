// User function Template for C++

class Solution{
    public:
        // Complete this function
    long long factorial(int N) {
        // Your code here
        if(N<=1)
            return 1;
        else
            return N*factorial(N-1);
    }

};