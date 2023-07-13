class Solution {
private:
    bool check (vector<int> base, vector<int> newBox) {
        return (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]);
    }

    int solveOptimal (int n, vector<vector<int>>& cuboids) {
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for (int curr = n-1; curr >= 0; curr--) {
            for (int prev = curr-1; prev >= -1; prev--) {
                // include the curret element
                int includeElement = 0;
                if (prev == -1 || check (cuboids[curr], cuboids[prev])) {
                    includeElement = cuboids[curr][2] + nextRow[curr + 1];
                }
                
                // exclude element
                int excludeElement = nextRow[prev + 1];
                
                currRow[prev+1] = max(includeElement, excludeElement);
            }

            nextRow = currRow;
        }
        
        return nextRow[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        sort (cuboids.begin(), cuboids.end());

        int ans = solveOptimal(cuboids.size(), cuboids);

        return ans;
    }
};