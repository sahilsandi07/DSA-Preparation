class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	int lastidx=n-1;
    	int firstidx=0;
    	int maxi=arr[n-1]+1;
    	for(int i=0;i<n;i++)
    	{
    	    if(i%2==0)
    	    {
    	        arr[i]+=(arr[lastidx]%maxi)*maxi;
    	        lastidx--;
    	    }
    	    else
    	    {
    	    arr[i]+=(arr[firstidx]%maxi)*maxi;
    	        firstidx++;
    	    }
    	}
    	for(int i=0;i<n;i++)
    	arr[i]/=maxi;

    	 
    }
};