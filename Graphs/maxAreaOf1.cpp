#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int& onesCnt) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        onesCnt++;

        vector<int> delrow = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> delcol = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int k = 0; k < 8; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, grid, onesCnt);
            }
        }
    }

public:
    // Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ansCnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int onesCnt = 0;
                    dfs(i, j, vis, grid, onesCnt);
                    ansCnt = max(ansCnt, onesCnt);
                }
            }
        }

        return ansCnt;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}