class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> matrix, int n) {
        // variables to keep track of required operations and row/column sums
        // code here 
        int maxAmongrowCol = INT_MIN;
        queue<int>q;;
        for(int i = 0 ; i < n ; i++){
            int sumrow = 0;
            int sumcol = 0;
            for(int j = 0 ; j < n ; j++){
                sumrow += matrix[i][j];
                sumcol += matrix[j][i];
                
            }
            q.push(sumrow);
            maxAmongrowCol = max(maxAmongrowCol , max(sumrow , sumcol));
           
        }
        
        int operations = 0;
        while(!q.empty()){
            operations += maxAmongrowCol - q.front();
            q.pop();
        }
        return operations;
    }
 
};
