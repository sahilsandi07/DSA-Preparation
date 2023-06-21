class Solution {
private:
    int solveTabSO(vector<int> &nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];    

        for (int i=1; i<n; i++) {
            int rob = prev2 + nums[i];
            int not_rob = prev1 + 0;

            int ans = max(rob, not_rob);

            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int> first;
        vector<int> second;

        for (int i=0; i<n; i++) {
            if (i != 0) first.push_back(nums[i]);
            if (i != n-1) second.push_back(nums[i]);
        }

        return max (solveTabSO(first), solveTabSO(second));
    }
};