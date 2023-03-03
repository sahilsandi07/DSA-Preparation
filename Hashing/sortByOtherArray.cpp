class Solution{
    public:
    
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        unordered_map<int,int>mp;
        vector<int>ans,t;
        for(auto i:A1){mp[i]++;}
        for(int i=0;i<M;i++){
            if(mp.find(A2[i])!=mp.end()){
                while(mp[A2[i]]--){
                    ans.push_back(A2[i]);
                }
                mp.erase(A2[i]);
            }
        }
        
        for(auto i:mp){
            if(i.second!=0){
                while(i.second--){
                    t.push_back(i.first);
                }
            }
        }
        sort(t.begin(),t.end());
        for(auto i:t){ans.push_back(i);}
        
        return ans;
    }
};