class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        long long flag=0, start=0, sum=0;
        vector <int> ans;
        if(s==0){
            return{-1};
        }
        for (int e=0; e<n; e++){
            sum+=arr[e];
            
            while (sum>s){
                sum-=arr[start];
                start++;
            }
            
            if (sum==s){
                ans.push_back(start+1);
                ans.push_back(e+1);
                flag=1;
                break;
            }
        }
        if(flag==0){
            return {-1};
        }
        else {
            return ans;
        }
    }
};