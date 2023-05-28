#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs (int node, int col, int color[], vector<int> adj[]) {
        color[node] = col;
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (!dfs (it, !col, color, adj)) return false;
            }
            
            else if (color[it] == col) return false;
        }
        
        return true;
    }
    
    bool bfs (int start, int V, int color[],vector<int> adj[]) {
        queue<int> q;
	    q.push(start); 
	    color[start] = 0; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        
	        for(auto it : adj[node]) {
	            // if the adjacent node is yet not colored
	            // you will give the opposite color of the node 
	            if(color[it] == -1) {
	                color[it] = !color[node]; 
	                q.push(it); 
	            }
	            // is the adjacent guy having the same color 
	            // someone did color it on some other path 
	            else if(color[it] == color[node]) {
	                return false; 
	            }
	        }
	    }
	    return true; 
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // this can be solved using both dfs and bfs
	    // dfs
	    int color[V];
	    for (int i=0; i<V; i++) color[i] = -1;
	    
	    for (int i=0; i<V; i++) {
	        if (color[i] == -1) {
	            // dfs call
	            // if (!dfs (i, 0, color, adj)) return false;
	            // bfs call
	            if (!bfs (i, V, color, adj)) return false;
	            
	        }
	    }
	    
	    return true;
	}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}