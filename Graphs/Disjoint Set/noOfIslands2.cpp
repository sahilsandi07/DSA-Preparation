#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int> size, parent;
    DisjointSet (int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    
    int findPar (int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    
    void Union (int u, int v) {
        int ulp_u = findPar (u);
        int ulp_v = findPar (v);
        
        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
        else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds (n * m);
        int vis[n][m];
        memset (vis, 0, sizeof vis);
        
        int cnt = 0;
        vector<int> ans;
        
        for (auto it : operators) {
            int row = it[0];
            int col = it[1];
            
            if (vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt ++;
            
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            
            for (int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if (vis[nrow][ncol] == 1) {
                        int nodeNum = row * m + col;
                        int newNodeNum = nrow * m + ncol;
                        
                        if (ds.findPar(nodeNum) != ds.findPar(newNodeNum)) {
                            cnt --;
                            ds.Union(nodeNum, newNodeNum);
                        }
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}