#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
    vector<int> size, parent;

    public:
    DisjointSet (int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i=0; i<=n; i++) parent[i] = i;
    }

    int findPar (int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize (int u, int v) {
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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        /*  Prims Algorithm */
        // // declare a priority queue or a min heap
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // //declare a visited array
        // vector<int> vis (V, 0);
        
        // // pq --> {wt, node}
        // pq.push({0, 0});
        
        // int sum = 0;
        
        // // iterate till pq becomes empty
        // while (!pq.empty()) {
        //     int wt = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();
            
        //     //if node i already visited, go get the next node
        //     if (vis[node]) continue;
        //     // otherwise welcome it and mark it as visited
        //     vis[node] = 1;
            
        //     sum += wt;
            
        //     for (auto it : adj[node]) {
        //         int adjNode = it[0];
        //         int edW = it[1];
                
        //         if (!vis[adjNode]) {
        //             pq.push({edW, adjNode});
        //         }
        //     }
        // }
        
        // return sum;
        
        /* Kruskals Algorithm */
        vector<pair<int, pair<int, int>>> edges;
        for (int i=0; i<V; i++){
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if (ds.findPar(u) != ds.findPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mstWt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}