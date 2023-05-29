#include <bits/stdc++.h>
using namespace std;

// Time And Space Complexity
// in the worst case if matrix has all O's
// then the dfs will traverse for O(V + E) for boundary traversal
// the worst case Space Complexity will be O(V)


class Solution {
  private:
    bool dfs (int node, vector<pair<int, int>> &visited, vector<int> adj[]) {
        visited[node].first = 1;
        visited[node].second = 1;
        
        // traverse the adjacent nodes now
        for (auto it : adj[node]) {
            // if the node is not visited
            if (!visited[it].first) {
                if (dfs (it, visited, adj)) return true;
            }
            
            // if the node is path visited
            else if (visited[it].second) return true;
        }
        
        visited[node].second = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<pair<int, int>> visited(V, make_pair(0, 0));

        for (int i=0; i<V; i++) {
            if (!visited[i].first) {
                if (dfs (i, visited, adj)) return true;
            }
        }
        
        return false;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}