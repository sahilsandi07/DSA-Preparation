#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        // step 1 : Create a priority queue
        priority_queue< pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>,
                        greater<pair<int, pair<int, int>>>> pq;
        
        // step 2 : Create a Distance 2D vector
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        
        pq.push({0, {0, 0}});
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        
        // step 3 : Iterate till queue becomes empty
        while (!pq.empty()) {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if (row == n-1 and col == m-1) return diff;
            
            for (int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >=0 && ncol < m) {
                    int newEffort = max (abs(grid[row][col] - grid[nrow][ncol]), diff);
                    if (newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        
        return 0; //unreachable
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}