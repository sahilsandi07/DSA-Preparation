class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        int uppercase[26] = {0};
        int lowercase[26] = {0};
        for (char c : str) {
            if (isupper(c)) {
                uppercase[c-'A']++;
            } else {
                lowercase[c-'a']++;
            }
        }
        string sorted_uppercase, sorted_lowercase;
        for (int i = 0; i < 26; i++) {
            sorted_uppercase += string(uppercase[i], 'A'+i);
            sorted_lowercase += string(lowercase[i], 'a'+i);
        }
        string output;
        int i = 0, j = 0;
        for (char c : str) {
            if (isupper(c)) {
                output += sorted_uppercase[i++];
            } else {
                output += sorted_lowercase[j++];
            }
        }
        return output;
    }
};