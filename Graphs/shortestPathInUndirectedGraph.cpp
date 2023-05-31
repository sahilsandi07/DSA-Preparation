#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // step 1 : create a graph
        vector<int> adj[N];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        // step 2 : create a queue and a distance array
        queue<int> q;
        vector<int> dist (N, 1e9);
        dist[src] = 0;
        q.push(src);
        
        // step 3 : find distances of each node until the queue becomes empty
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        
        // step 4 : If path is not possible to specific node
        // add -1 as a path
        for (int i=0; i<N; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}