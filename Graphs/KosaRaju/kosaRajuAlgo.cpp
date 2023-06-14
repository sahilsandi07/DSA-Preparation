#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void dfs (int node, vector<int> &vis, stack<int> &st, vector<vector<int>>& adj) {
        vis[node] = 1;
        
        for (auto it :  adj[node]) {
            if (!vis[it]) {
                dfs (it, vis, st, adj);
            }
        }
        
        st.push(node);
    }
    
    void dfsT (int node, vector<int> &vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfsT (it, vis, adj);
            }
        }
    }
    
	public:
    int kosaraju(int V, vector<vector<int>>& adj) {
        // Sort all edges according to the finishing time
        vector <int> vis (V, 0);
        stack<int> st;
        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                dfs (i, vis, st, adj);
            }
        }
        
        // Reverse the Graph
        vector<vector<int>> adjT(V);
        for (int i=0; i<V; i++) {
            vis[i] = 0;
            
            for (auto it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        
        // Do a DFS on adjT
        int scc = 0;
        vis.assign(V, 0); 
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            if (!vis[node]) {
                scc++;
                dfsT(node, vis, adjT);
            }
        }
        
        return scc;
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
