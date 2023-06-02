#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> tar) {
        // step 1 : crete a queue
        queue<pair<int, pair<int, int>>> q;
        
        // step 2 : create a distance gird of same grid size
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist (n, vector<int> (m, 1e9));
        
        // step 3 : Initialise required paragraphs
        int srcRow = src.first;
        int srcCol = src.second;
        
        dist[srcRow][srcCol] = 0;
        
        int tarRow = tar.first;
        int tarCol = tar.second;
        
        if (srcRow == tarRow && srcCol == tarCol) return 0;
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        
        // step 4 : push initial configuration in the queue
        q.push({0, {srcRow, srcCol}});
        
        // step 5 : Iterate till queue becomes empty
        while (!q.empty()) {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for (int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = 1 + dis;
                    if (nrow == tarRow && ncol == tarCol) {
                        return dis + 1;
                    }
                    q.push({1 + dis, {nrow, ncol}});
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}