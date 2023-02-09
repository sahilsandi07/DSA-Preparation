class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        for (int i=0; i<n; i++){
            int current_index = arr[i] - 1;
            while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[current_index]){
                swap (arr[i], arr[current_index]);
                current_index = arr[i] - 1;
            }
        }
        
        for (int i=0; i<n; i++){
            if (arr[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    } 
};