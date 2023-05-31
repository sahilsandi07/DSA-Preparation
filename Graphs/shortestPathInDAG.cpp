#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
     void topoSort (int node, int visited[], vector<pair<int, int>> adj[], stack<int> &st) {
         visited[node] = 1;
         
         for (auto it : adj[node]) {
             int v = it.first;
             if (!visited[v]) {
                 topoSort (v, visited, adj, st);
             }
         }
         
         st.push(node);
     }
  public:
     vector<int> shortestPath(int V, int M, vector<vector<int>>& edges){
         
        // Step 1 : Create a Graph
        vector<pair<int, int>> adj[V];
        for (int i=0; i<M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        // Step 2 : Perform toposort
        int visited[V] = {0};
        stack<int> st;
        for (int i=0; i<V; i++) {
            if (!visited[i]) {
                topoSort (i, visited, adj, st);
            }
        } 
        
        //Step 3 : Find The Shortest Distances of each Node on the top of the stack
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                } 
            }
        }
        
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        
        return dist;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}