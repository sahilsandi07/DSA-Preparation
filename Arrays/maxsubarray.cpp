class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    
    int maxSubarraySum(int arr[], int n){
        
        int res=arr[0];
        int maxEnding=arr[0];
        
        for(int i=1; i<n; i++){
            maxEnding=max(maxEnding+arr[i],arr[i]);
            res=max(res,maxEnding);
        }
        
        return res;
        
    }
    
    int circularSubarraySum(int a[], int n){
        
        int max_normal=maxSubarraySum(a,n);
        
        if (max_normal<0){
            return max_normal;
        }
        
        int a_sum=0;
        for (int i=0; i<n; i++){
            a_sum+=a[i];
            a[i] = -a[i];
        }
        
        int max_circular= a_sum + maxSubarraySum(a,n);
        
        return max(max_normal, max_circular);
        
    }
};