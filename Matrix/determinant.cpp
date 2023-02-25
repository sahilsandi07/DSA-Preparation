class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // Base case for 1x1 matrix
        if (n == 1) {
            return matrix[0][0];
        }
    
        int det = 0;  // initialize determinant to zero
    
        // Choose any row or column to find cofactors
        for (int j = 0; j < n; j++) {
            // Find cofactor for matrix[0][j]
            vector<vector<int>> submatrix(n - 1, vector<int>(n - 1));
            for (int i = 1; i < n; i++) {
                int k = 0;
                for (int jj = 0; jj < n; jj++) {
                    if (jj != j) {
                        submatrix[i - 1][k] = matrix[i][jj];
                        k++;
                    }
                }
            }
            int cofactor = ((j % 2 == 0) ? 1 : -1) * determinantOfMatrix(submatrix, n - 1);
            det += matrix[0][j] * cofactor;
        }
    
        return det;
    }
};