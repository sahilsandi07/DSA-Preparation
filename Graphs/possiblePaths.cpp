#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<int> adj[], int visited[], int src, int dst) {
        if (src == dst) {
            return 1;
        }

        visited[src] = 1;
        int count = 0;

        for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                count += dfs(adj, visited, neighbor, dst);
            }
        }

        visited[src] = 0;
        return count;
    }

    int countPaths(int V, vector<int> adj[], int source, int destination) {
        int visited[V] = {0};
        return dfs(adj, visited, source, destination);
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
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}