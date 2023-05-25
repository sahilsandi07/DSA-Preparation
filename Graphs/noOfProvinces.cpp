#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs (int node, vector<int> adjLs[], int visited[]) {
        visited[node] = 1;
        for (auto it : adjLs[node]) {
            if (!visited[it]) {
                dfs (it, adjLs, visited);
            }
        }
    }
  
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V];
        
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (adj[i][j] == 1 and i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        int visited[V] = {0};
        int cnt = 0;
        
        for (int i=0; i<V; i++) {
            if (!visited[i]) {
                cnt ++;
                dfs (i, adjLs, visited);
            }
        }
        
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}