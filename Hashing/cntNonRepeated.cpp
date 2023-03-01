class Solution{
    public:
    
    int countNonRepeated(int arr[], int n)
    {
        unordered_map<int, int> mp;
        for (int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        int cnt = 0;
        for (auto it: mp){
            if (it.second == 1){
                cnt ++;
            }
        }
        
        return cnt;
    }

};