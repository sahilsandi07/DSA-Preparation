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
    int Solve(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int cntExtra = 0;
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            if (ds.findPar(u) == ds.findPar(v)) {
                cntExtra ++;
            }
            else {
                ds.Union (u, v);
            }
        }
        
        int connectedComponents = 0;
        for (int i=0; i<n; i++) {
            if (ds.parent[i] == i) {
                connectedComponents++;
            }
        }
        
        int ans = connectedComponents - 1;
        
        if (cntExtra >= ans) return ans;
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}