class Solution
{
    public:
    
    int findNumberOfTriangles(int arr[], int n)
    {
      sort(arr , arr+n);

      int count = 0;
      
      for(int i = n-1 ; i>=0 ; i--){
          
          int s = 0 ;
          int e= i-1;
      
          while(s < e){
            
            if (arr[s] + arr[e] > arr[i]){
                  count = count + (e-s);
                  e--;
            }
            else
                 s++;
          }
          
       }
       return count;
    }
};