class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis (n, 0);
        vis[0] = 1;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int currRoom = q.front();
            q.pop();

            for (auto key : rooms[currRoom]) {
                if (!vis[key]) {
                    vis[key] = true;
                    q.push(key);
                }
            }
        }

        for (bool roomVisited : vis) {
            if (!roomVisited) {
                return false;
            }
        }

        return true;
    }
};