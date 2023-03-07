class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        unordered_map<int,int> mp;

        if(str1.size()!=str2.size()) return 0;

        for(int i=0;i<str1.size();i++){

            if(mp.find(str1[i])!=mp.end()){

                if(mp[str1[i]]!=str2[i]) return 0;

            }

            else{

                mp[str1[i]]=str2[i];

            }

        }

        mp.clear();

        for(int i=0;i<str1.size();i++){

            if(mp.find(str2[i])!=mp.end()){

                if(mp[str2[i]]!=str1[i]) return 0;

            }

            else{

                mp[str2[i]]=str1[i];

            }

        }

        return 1;
    }
};