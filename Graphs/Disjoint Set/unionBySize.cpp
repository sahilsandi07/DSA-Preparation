#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
    vector<int> size, parent;

    public:
    DisjointSet (int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i=0; i<=n; i++) parent[i] = i;
    }

    int findPar (int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize (int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same Parent!\n";
    }
    else {
        cout << "Did Not Have the Same Parent.\n";
    }

    ds.unionBySize(3, 7);
    ds.unionBySize(5, 6);  

    if (ds.findPar(3) == ds.findPar(7)) {
        cout << "Same Parent!\n";
    }
    else {
        cout << "Did Not Have the Same Parent.\n";
    }

    return 0;  
}