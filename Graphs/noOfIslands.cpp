#include <bits/stdc++.h>
using namespace std;


class Solution {
  private:
    void bfs (int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //traverse all neighbour lands of current land
            //And current land can possibly be preent in all the 8 direcions
            for (int delRow = -1; delRow <= 1; delRow++) {
                for (int delCol = -1; delCol <= 1; delCol++) {
                    int nrow = row + delRow;
                    int ncol = col + delCol;
                    
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            
        }
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited (n, vector<int> (m, 0));
        int cnt = 0;
        
        for (int row =0; row<n; row++) {
            for (int col = 0; col<m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    cnt ++;
                    bfs (row, col, grid, visited);
                }
            }
        }
        
        return cnt;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}