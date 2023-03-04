class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        unordered_set <int> s;
        for (int i=0; i<n; i++){
            s.insert(arr[i]);
        }
        
        int res = 1;
        
        for (auto x : s){
            if (s.find(x-1) == s.end()){
                int curr = 1;
                while (s.find(x + curr) != s.end()){
                    curr ++;
                }
                res = max(res, curr);
            }
        }
        return res;
    }
};