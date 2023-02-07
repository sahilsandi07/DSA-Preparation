//User function Template for C++

// Function to find maximum for every adjacent pairs in the array.
void maximumAdjacent(int n, int arr[]){
     for(int i=0; i<n-1; i++){
         cout<<max(arr[i],arr[i+1])<<" ";
     }
}