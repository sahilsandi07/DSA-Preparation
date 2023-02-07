//User function Template for C++

class Solution{
  public:
    //Complete this function
    int countDigits(int n)
    {
       //Your code here
       if (n<10){
           return 1;
       }
       int cnt = 0;
       while(n>0){
           n=n/10;
           cnt++;
       }
       return cnt;
    }
};