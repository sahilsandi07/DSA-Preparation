class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int r, int c, int x) 
    {
        
        int i = 0, j = c-1;
        
        while (i<r && j>=0){
            if (matrix[i][j] == x){
                return 1;
            }
            
            else if (matrix[i][j] > x){
                j--;
            }
            
            else {
                i++;
            }
        }
        
        return 0;
    }
};