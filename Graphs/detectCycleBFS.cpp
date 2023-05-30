#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int inDegree[V] = {0};
        for (int i=0; i<V; i++) {
            for (auto it : adj[i]) {
                inDegree[it] ++;
            }
        }
        
        queue<int> q;
        for (int i=0; i<V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int cnt = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            cnt++;
            
            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return cnt == V ? false : true;
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