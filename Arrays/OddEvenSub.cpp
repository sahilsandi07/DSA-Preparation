
class Solution{
    public:
    //Complete this function
    //Function to find the length of longest subarray of even and odd numbers.
    int maxEvenOdd(int arr[], int n) 
    { 
       int temp=0, max=0;
       for(int i=0; i<n-1; i++){
           if (arr[i+1]%2!=arr[i]%2){
               temp++;
               if(max<temp){
                   max=temp;
               }
           }
           else{
               temp=0;
           }
       }
       return ++max;
    } 
};