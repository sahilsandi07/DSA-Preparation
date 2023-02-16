class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {   
        
        vector<int> res(n+m);   // Time Complexity: O(n+m(log(n+m)))
        
        for (int i=0; i<n; i++){
            res[i] = arr1[i];
        }
        
        int j=n;
        for (int i=0; i<m; i++){
            res[j] = arr2[i];
            j++;
        }
        
        sort(res.begin(), res.end());
        
        auto last = unique(res.begin(), res.end());  // remove duplicates
    
        res.erase(last, res.end());  // erase the extra elements
        
        return res;
    }
};