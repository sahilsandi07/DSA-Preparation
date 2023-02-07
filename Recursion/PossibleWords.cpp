//User function Template for C++

class Solution
{
    public:
    vector <string> keys={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector <string> ans;
    
    void helper(int a[], int n, string temp, int i){
        
        if (i==n){
            ans.push_back(temp);
            return;
        }
        
        for (int j=0;j<keys[a[i]].size();j++){
            helper(a,n,temp+keys[a[i]][j],i+1);
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        helper(a,N,"",0);
        return ans;
    }
};