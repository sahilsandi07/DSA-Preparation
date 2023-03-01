class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_set<int> set_a;
        
        for (int i=0; i<n; i++){
            set_a.insert(a[i]);
        }
        
        for (int i=0; i<m; i++){
            set_a.insert(b[i]);
        }
        
        return set_a.size();
    }
};