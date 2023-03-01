class Solution{
public:
    long long int findSubarray(vector<long long int> &arr, int n ) {

        //code here
    
        long long cnt = 0,preSum = 0;
    
        unordered_map<long long, long long>mp;
        
        for(int i = 0; i < n; i++){ 
    
            preSum += arr[i];
    
            mp[preSum]++;

            if(preSum == 0)  cnt++;
    
        }
    
        for(auto &i : mp)   cnt += ((i.second)*(i.second-1))/2;

        return cnt;
    
    }
};