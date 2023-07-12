class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort envelopes based on width in ascending order
        // If width is the same, sort based on height in descending order
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        int n = envelopes.size();
        vector<int> dp;
        
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if (it == dp.end()) {
                dp.push_back(envelopes[i][1]);
            } else {
                *it = envelopes[i][1];
            }
        }

        return dp.size();
    }
};
