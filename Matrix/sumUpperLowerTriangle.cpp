class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& mat, int n)
    {
        vector<int> res;
        int upper_sum = 0;
        int lower_sum = 0;
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j >= i) {
                    upper_sum += mat[i][j];
                }
                if (i >= j) {
                    lower_sum += mat[i][j];
                }
            }
        }
        
        res.push_back(upper_sum);
        res.push_back(lower_sum);
        return res;
    }
};