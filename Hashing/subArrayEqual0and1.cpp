class Solution{
  public:
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //using hashmap
        map<int,int>mp;
        int x =0;
        int ans =0;
        for(int i =0; i<n;i++){
            mp[x]++;
            if(arr[i])
                x++;
            else 
                x--;
            ans += mp[x];
        }
        return ans;
    }
};