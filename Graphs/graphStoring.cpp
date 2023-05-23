#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    
    /*Adjacency Matrix    Space Complexity is O(N^2)*/
    int adj[n+1][m+1];

    for (int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    /*Adjacency List    Space Complexity is O(2N)   Because, the degree of the 
    graph is twicw the number of the edges.*/

    int n1, m1;
    cin >> n1 >> m1;
    vector<int> adjL[n1+1];

    for (int i=0; i<m1; i++)
    {
        int  u, v;
        cin >> u >> v;

        adj[u].push_back(v);

        // For directed graph u ---> v
        // No need for below line
        adj[v].push_back(u);
    }
    return 0;
}