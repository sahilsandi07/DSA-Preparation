class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int N) 
    { 
        int maxIndex = 0;
        for (int i=0; i<N; i++){
            for (int j=N-1; j>i; j--){
                if (arr[i]<=arr[j]){
                    int temp=j-i;
                    maxIndex=max(temp,maxIndex);
                    break;
                }
            }
        }
        return maxIndex;
    }
};