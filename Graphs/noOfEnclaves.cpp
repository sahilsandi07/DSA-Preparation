#include <bits/stdc++.h>
using namespace std;

// Time And Space Complexity
// in the worst case if matrix has all O's
// then the dfs will traverse for O(N*M x 4) + O(N) for boundary traversal
// the worst case Space Complexity will be O(N x M)

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis( n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i == 0 or j == 0 or i == n-1 or j == m-1) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, 1, 0};
	    int delcol[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m
                and !vis[nrow][ncol] and grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        int cnt = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1 and !vis[i][j]) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}