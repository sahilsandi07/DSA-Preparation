//User function Template for C++

class Solution{
  public:
    //Complete this function
    int digitalRoot(int n)
    {
        //Your code here
        if(n==0){
            return 0;
        }
        int a= (n%10)+digitalRoot(n/10);
        if (a>=10){
            return (a%10)+digitalRoot(a/10);
        }
        else{
            return a;
        }
    }
};