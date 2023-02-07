
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) { 
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            if(arr[i]>0)
                mp[arr[i]]++;
        for(int i=0;i<n;i++)
            if(mp.find(i+1)==mp.end())
                return i+1;
        return arr[n-1]+1;
    }
};