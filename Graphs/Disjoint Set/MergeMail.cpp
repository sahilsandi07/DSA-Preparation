#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent, size;

    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ultU = findUltimateParent(u);
        int ultV = findUltimateParent(v);

        if (ultU == ultV)
            return;

        if (rank[ultU] < rank[ultV])
            parent[ultU] = ultV;

        else if (rank[ultU] > rank[ultV])
            parent[ultV] = ultU;

        else
        {
            parent[ultV] = ultU;
            rank[ultU]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultU = findUltimateParent(u);
        int ultV = findUltimateParent(v);

        if (ultU == ultV)
            return;

        if (size[ultU] < size[ultV])
        {
            parent[ultU] = ultV;
            size[ultV] += size[ultU];
        }

        else
        {
            parent[ultV] = ultU;
            size[ultU] += size[ultV];
        }
    }
};

class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& mat)
    {
        int n = mat.size();
        
        DisjointSet ds(n);
        unordered_map<string, int> mp;
        
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<mat[i].size(); j++)
            {
                string mail = mat[i][j];
                if(mp.find(mail) == mp.end())
                {
                    mp[mail] = i;
                }
                else
                {
                    ds.unionBySize(mp[mail], i);
                }
            }
        }
        
        vector<string> merge[n];
        for(auto it:mp)
        {
            string mail = it.first;
            int node = ds.findUltimateParent(it.second);
            
            merge[node].push_back(mail);
        }
        
        
        vector<vector<string>> ans;
        for(int i=0; i<n; i++)
        {
            if(merge[i].size())
            {
                sort(merge[i].begin(), merge[i].end());
                
                vector<string> temp;
                temp.push_back(mat[i][0]);
                
                for(auto it:merge[i])
                {
                    temp.push_back(it);
                }
                
                ans.push_back(temp);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}