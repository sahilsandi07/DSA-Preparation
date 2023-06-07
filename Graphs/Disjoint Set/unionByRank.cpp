#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
    vector<int> rank, parent;

    public:
    DisjointSet (int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i=0; i<=n; i++) parent[i] = i;
    }

    int findPar (int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank (int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }

        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }

        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u] ++;
        }
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same Parent!\n";
    }
    else {
        cout << "Did Not Have the Same Parent.\n";
    }

    ds.unionByRank(3, 7);
    ds.unionByRank(5, 6);  

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same Parent!\n";
    }
    else {
        cout << "Did Not Have the Same Parent.\n";
    }

    return 0;  
}