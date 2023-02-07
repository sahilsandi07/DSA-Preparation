// User function Template for C++

class Solution{
public:
    
    vector<int>v;
    void helper(int n){
        if(n<=0){
            v.push_back(n);
            return;
        }
        
        v.push_back(n);
        helper(n-5);
        v.push_back(n);
    }
    
    vector<int> pattern(int n){
        helper (n);
        return v;
    }
};