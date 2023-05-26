#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool detectCycle (int src, vector<int> adj[], int visited[]) {
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push ({src, -1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push({it, node});
                }
                
                else if (parent != it) {
                    return true;
                }
            }
        }
        
        return false;
    }

    bool detectCycleDFS (int node, int parent, vector<int> adj[], int visited[]) {
        visited[node] = 1;
        
        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                if (detectCycleDFS (adjNode, node, adj, visited) == true) return true;
            }
            
            else if (adjNode != parent) return true;
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int visited[V] = {0};
        
        for (int i=0; i<V; i++) {
            if (!visited[i]) {
                if (detectCycle (i, adj, visited)) return true;
            }
        }
        
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}