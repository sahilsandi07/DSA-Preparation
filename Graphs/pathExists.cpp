#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    bool bfs (int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis,
    int targetRow, int targetCol) {            // O(N x N x 4) in worst case, as every cell
        vis[row][col] = 1;                     // cell will visit it four neighbours
        int n = grid.size();
        queue<pair<int, int>> q;
        q.push({row, col});
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n and grid[nrow][ncol] != 0
                and !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    if (nrow == targetRow && ncol == targetCol) {
                        return true;
                    }
                    q.push({nrow, ncol});
                }
            }
        }
        
        return false;
    }
    public:
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> vis (n, vector<int> (n, 0));
        
        int targetRow;
        int targetCol;
        
        for (int i=0; i<n; i++) {                   // O(N x N) in worst case
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 2) {
                    targetRow = i;
                    targetCol = j;
                }
            }
        }
        
        for (int i=0; i<n; i++) {                   // O(N x N) in worst case
            for(int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    // we will start traversing from here
                    if (bfs (i, j, grid, vis, targetRow, targetCol)) return true;
                }
            }
        }
        
        return false;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}