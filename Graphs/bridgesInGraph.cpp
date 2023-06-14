#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Utility function for DFS traversal
    void DFS(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;

        // Traverse all adjacent nodes
        for (int i = 0; i < adj[node].size(); i++) {
            int adjacent = adj[node][i];

            // If the adjacent node is not visited, perform DFS on it
            if (!visited[adjacent])
                DFS(adjacent, adj, visited);
        }
    }

    // Function to find if the given edge is a bridge in the graph.
    int isBridge(int V, vector<int> adj[], int c, int d) {
        // Remove the edge (c, d) temporarily
        for (int i = 0; i < adj[c].size(); i++) {
            if (adj[c][i] == d) {
                adj[c].erase(adj[c].begin() + i);
                break;
            }
        }

        // Remove the edge (d, c) temporarily
        for (int i = 0; i < adj[d].size(); i++) {
            if (adj[d][i] == c) {
                adj[d].erase(adj[d].begin() + i);
                break;
            }
        }

        // Perform DFS from node c and check if node d is visited.
        vector<bool> visited(V, false);
        DFS(c, adj, visited);

        // Restore the removed edges
        adj[c].push_back(d);
        adj[d].push_back(c);

        // If node d is visited, the edge (c, d) is not a bridge.
        if (visited[d])
            return 0;
        else
            return 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}
