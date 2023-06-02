#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        /* Method 2 : Set */
        
        // step 1 : Create a Set
        set<pair<int, int>> st;
        st.insert ({0, src});
        
        // step 2 : Create a dist vector and Intialise to Infinity
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        // step 3 : Iterate till Set becomes empty
        while (!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if (dis + edgeWeight < dist[adjNode]) {
                    // if it is already visited
                    if (dist[adjNode] != 1e9) {
                        st.erase ({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeWeight;
                    st.insert ({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}