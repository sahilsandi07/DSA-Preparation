class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int A[], int n)
    {
       //Your code here
       int cnt=0;
       int res=0;
       for (int i=0; i<n-1; i++){
           if(A[i]<A[i+1]){
               cnt+=1;
           }
           else{
               cnt=0;
           }
           res=max(res,cnt);
       }
       return res;
    }
};