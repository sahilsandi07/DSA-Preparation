//User function Template for C++


//Function to return the lexicographically sorted power-set of the string.
vector <string> powerSet(string s)
{
   vector<string> subsets;
   int n = s.length();
   int psize = 1 << n;
   for (int i = 0; i < psize; i++) {
       string subset = "";
       for (int j = 0; j < n; j++) {
           if ((i & (1 << j)) != 0) {
               subset += s[j];
           }
       }
       subsets.push_back(subset);
   }
   return subsets;
}