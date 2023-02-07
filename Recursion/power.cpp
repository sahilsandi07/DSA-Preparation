
class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
        long long temp; 
        if (R == 0) {
            return 1;
        }
        if (R == 1) {
            return N%1000000007;
        }
        temp = power(N, R / 2);
        if (R % 2 == 0) {
            return  (temp * temp)%1000000007; 
        }
        else {
            return N * ((temp * temp)%1000000007)%1000000007;
        }
    }

};