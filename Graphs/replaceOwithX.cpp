#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs (int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        for (int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if (nrow >=0 and nrow < n and ncol >= 0 and ncol < m
            and !vis[nrow][ncol] and mat[nrow][ncol] == 'O') {
                dfs (nrow, ncol, vis, mat);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> visited (n , vector<int> (m, 0));
        
        // traverse first and last row
        for (int i=0; i<m; i++) {
            if (!visited[0][i] && mat[0][i] == 'O') {
                dfs (0, i, visited, mat);
            }
            if (!visited[n-1][i] && mat[n-1][i] == 'O') {
                dfs (n-1, i, visited, mat);
            }
        }
        
        // traverse first and last column
        for (int i=0; i<n; i++) {
            if (!visited[i][0] && mat[i][0] == 'O') {
                dfs (i, 0, visited, mat);
            }
            if (!visited[i][m-1] && mat[i][m-1] == 'O') {
                dfs (i, m-1, visited, mat);
            }
        }
        
        // Now simply traverse the matrix
        // and convert the O's in the matrix that are not yet visited by DFS
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!visited[i][j]) {
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}