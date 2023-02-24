class Solution
{   
    public:
    //Function to add two matrices.
    vector<vector<int> > sumMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        // code here
        int rows_A = A.size();
        int cols_A = A[0].size();
        int rows_B = B.size();
        int cols_B = B[0].size();
        
        if (rows_A != rows_B || cols_A != cols_B) {  // handle edge case where A and B have different dimensions
            return {{-1}};
        }
        
        vector<vector<int>> res(rows_A, vector<int>(cols_A));  // initialize the res vector with the correct dimensions
        
        for (int i=0; i<rows_A; i++){
            for (int j=0; j<cols_A; j++){
                res[i][j] = A[i][j] + B[i][j];
            }
        }
        
        return res;
    }
};
