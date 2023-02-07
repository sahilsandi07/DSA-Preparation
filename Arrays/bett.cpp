//User function Template for C++

class Solution{
    public:
    
        int betBalance(string result)
        {
            int sum=4, n=result.length();
            int bet=1;
            for(int i=0; i<n; i++){
                if(sum<bet) return -1;
                if(result[i]=='W'){
                    sum+=bet;
                    bet=1;
                }
                else if(sum>=bet){
                    sum-=bet;
                    bet=2*bet;
                }
            }
            return sum;
        }
    
};