class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        unordered_map<char, int> mp;
        
        for (int  i=0; i< str.length(); i++){
            mp[str[i]]++;
        }
        
        int maxO = 0;
        
        for (auto it : mp){
            if (it.second > maxO){
                maxO = it.second;
            }
        }
        
        for (char c = 'a'; c <= 'z'; c++) {
            if (mp[c] == maxO) {
                return c;
            }
        }
    }

};