class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
		//sort the arrays arrival and departure
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i = 1, j = 0, res = 1, curr = 1;
    	
    	while (i<n && j<n){
    	    if (arr[i] <= dep[j]){
    	        curr++;
    	        i++;
    	    }
    	    
    	    else {
    	        curr--;
    	        j++;
    	    }
    	    
    	    res = max(res, curr);
    	}
    	
    	return res;
    }
};