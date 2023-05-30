#include <bits/stdc++.h>
using namespace std;

class Solution {
//   private:
//     bool dfs (int node, vector<pair<int, int>> &visited, vector<int> adj[],
//     vector<int>& checkSafe) {
//         visited[node].first = 1;
//         visited[node].second = 1;
//         checkSafe[node] = 0;
        
//         // traverse the adjacent nodes now
//         for (auto it : adj[node]) {
//             // if the node is not visited
//             if (!visited[it].first) {
//                 if (dfs (it, visited, adj, checkSafe)) return true;
//             }
            
//             // if the node is path visited
//             else if (visited[it].second) return true;
//         }
        
//         checkSafe[node] = 1;
//         visited[node].second = 0;
//         return false;
//     }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // vector<pair<int, int>> visited(V, make_pair(0, 0));
        // vector<int> checkSafe (V, 0);
        // for (int i=0; i<V; i++) {
        //     if (!visited[i].first) {
        //         dfs (i, visited, adj, checkSafe);
        //     }
        // }
        
        // vector<int> safeNodes;
        // for (int i=0; i<V; i++) {
        //     if (checkSafe[i] == 1) {
        //         safeNodes.push_back(i);
        //     }
        // }
        
        // return safeNodes;
        vector<int> adjRev[V];
        int inDegree[V] = {0};
        for (int i=0; i<V; i++) {
            for (auto it : adj[i]) {
                adjRev[it].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> safeNodes;
        for (int i=0; i<V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for (auto it : adjRev[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}