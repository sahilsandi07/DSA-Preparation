class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
            graph[i] = vector<int>();

        for (const auto& edge : edges) {
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                unordered_set<int> componentSet;
                int count = dfs(i, vis, graph, componentSet);
                if (componentSet.size() == 1 && componentSet.count(count - 1))
                    ans++;
            }
        }

        return ans;
    }

    int dfs(int src, vector<bool>& vis, vector<vector<int>>& graph, unordered_set<int>& componentSet) {
        vis[src] = true;
        componentSet.insert(graph[src].size());
        int ans = 1;
        for (int nbr : graph[src]) {
            if (!vis[nbr]) {
                ans += dfs(nbr, vis, graph, componentSet);
            }
        }
        return ans;
    }
};
