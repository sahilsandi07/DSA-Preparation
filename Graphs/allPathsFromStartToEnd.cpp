class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size() - 1;
        vector<vector<int>> ans;
        
        queue<vector<int>> q;
        q.push({0}); // Start with the source node (0)
        
        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();
            
            int currNode = path.back();
            
            if (currNode == target) {
                ans.push_back(path);
            } else {
                for (int neighbor : graph[currNode]) {
                    vector<int> newPath = path;
                    newPath.push_back(neighbor);
                    q.push(newPath);
                }
            }
        }
        
        return ans;
    }
};
