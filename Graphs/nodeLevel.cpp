#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int bfs(int node, vector<int> adj[], int visited[], int X) {
        visited[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, 0});

        while (!q.empty()) {
            int currentNode = q.front().first;
            int level = q.front().second;
            q.pop();

            for (auto it : adj[currentNode]) {
                if (!visited[it]) {
                    if (it == X) {
                        return level + 1;
                    }
                    visited[it] = 1;
                    q.push({it, level + 1});
                }
            }
        }

        return -1;
    }

public:
    int nodeLevel(int V, vector<int> adj[], int X) {
        if (X == 0)
            return 0;
        int visited[V] = {0};

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return bfs(i, adj, visited, X);
            }
        }

        return -1;
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}
