class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        ///Always Remember that colums size is always gong to be same as size of matrix[0]
        
        int R = matrix.size();
        int C = matrix[0].size();
        bool row[R], col[C];
    
        // Initialize row[] and col[] arrays to false
        for (int i = 0; i < R; i++) {
            row[i] = false;
        }
        for (int j = 0; j < C; j++) {
            col[j] = false;
        }
    
        // Traverse the matrix and mark the rows and columns
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == 1) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
    
        // Modify the matrix based on the marked rows and columns
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};