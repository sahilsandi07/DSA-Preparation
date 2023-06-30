class Solution {
public:
    bool isPossibleToWalk(int row, int col, int day, const vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        // Perform a depth-first search (DFS) to check if we can reach the bottom row
        vector<vector<int>> visited(row, vector<int>(col, 0));
        stack<pair<int, int>> st;

        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0) {
                st.push({0, i});
                visited[0][i] = 1;
            }
        }

        while (!st.empty()) {
            int r = st.top().first;
            int c = st.top().second;
            st.pop();

            if (r == row - 1) {
                return true; // Reached the bottom row
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < col && !visited[nr][nc] && grid[nr][nc] == 0) {
                    st.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }

        return false; // Couldn't reach the bottom row
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1;
        int right = cells.size();
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isPossibleToWalk(row, col, mid, cells)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

private:
    const vector<int> dr = {-1, 0, 1, 0};
    const vector<int> dc = {0, 1, 0, -1};
};