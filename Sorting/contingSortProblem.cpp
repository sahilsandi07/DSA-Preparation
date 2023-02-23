class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        vector<int> v(26, 0);
        for(int i=0; i<arr.length(); ++i) {
            v[arr[i] - 'a']++;
        }
        arr = "";
        for(int i=0; i<v.size(); ++i) {
            while(v[i] > 0) {
                arr.push_back(i + 'a');
                v[i]--;
            }
        }
        
        return arr;
    }
};