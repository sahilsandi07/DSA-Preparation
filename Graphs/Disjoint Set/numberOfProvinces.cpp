#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int> parent, size;
    DisjointSet (int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        
        for(int i=0; i<= n; i++) {
            parent[i] = i;
            //size[i] = 1;
        }
    }
    
    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    
    void UnionBySize (int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        
        if (ulp_u == ulp_v) return;
        
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
//   private:
//     void dfs (int node, vector<int> adjLs[], int visited[]) {
//         visited[node] = 1;
//         for (auto it : adjLs[node]) {
//             if (!visited[it]) {
//                 dfs (it, adjLs, visited);
//             }
//         }
//     }
  
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        /* Using Graph traversals */
        // vector<int> adjLs[V];
        
        // for (int i=0; i<V; i++) {
        //     for (int j=0; j<V; j++) {
        //         if (adj[i][j] == 1 and i != j) {
        //             adjLs[i].push_back(j);
        //             adjLs[j].push_back(i);
        //         }
        //     }
        // }
        
        // int visited[V] = {0};
        // int cnt = 0;
        
        // for (int i=0; i<V; i++) {
        //     if (!visited[i]) {
        //         cnt ++;
        //         dfs (i, adjLs, visited);
        //     }
        // }
        
        // return cnt;
        
        /* Using DSU */
        DisjointSet ds(V);
        
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (adj[i][j] == 1) {
                    ds.UnionBySize(i, j);
                }
            }
        }
        
        int cnt = 0;
        for (int i=0; i<V; i++) {
            if (ds.parent[i] == i) {
                cnt ++;
            }
        }
        
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}