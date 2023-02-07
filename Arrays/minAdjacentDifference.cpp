
class Solution{
    public:
    //Function to find minimum adjacent difference in a circular array.
    // arr[]: input array
    // n: size of array
    int minAdjDiff(int arr[], int n){    
        // Your code here
        int min_num=arr[0];

        int diff=abs(arr[0]-arr[n-1]);

        for(int i=1;i<n;i++){

            int new_diff=abs(min_num-arr[i]);

            if(new_diff<diff){

                diff=new_diff;

            }

            min_num=arr[i];

        }

        return diff;
        
    }
};