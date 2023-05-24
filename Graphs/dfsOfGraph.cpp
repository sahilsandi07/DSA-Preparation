#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs (int node, vector<int> adj[], vector<int> vis, vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);

        //traverse all the neighbours
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs (it, adj, vis, ls);
            }
        }
    }


    public: 
    vector<int> dfsOfGraph (int V, vector<int> adj[]) {
        vector<int> vis[V] = {0};
        int start = 0;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
}