class Solution {
private:
    int solveRec (vector<int>& nums1, vector<int>& nums2, int index, bool swapped) {
        // base case
        if (index == nums1.size()) {
            return 0;
        }

        int ans = INT_MAX;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // here is the main catch of the code
        if (swapped) {
            swap (prev1, prev2);
        }

        // if we decide to swap
        if (nums1[index] > prev2 && nums2[index] > prev1) {
            ans = min (ans, 1 + solveRec(nums1, nums2, index + 1, 1));
        }

        // if we do not swap
        if (nums1[index] > prev1 && nums2[index] > prev2) {
            ans = solveRec (nums1, nums2, index + 1, 0);
        }

        return ans;
    }

    int solveMem (vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>> &dp) {
        // base case
        if (index == nums1.size()) {
            return 0;
        }

        if (dp[index][swapped] != -1) {
            return dp[index][swapped];
        }

        int ans = INT_MAX;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // here is the main catch of the code
        if (swapped) {
            swap (prev1, prev2);
        }

        // if we decide to swap
        if (nums1[index] > prev2 && nums2[index] > prev1) {
            ans = min (ans, 1 + solveMem(nums1, nums2, index + 1, 1, dp));
        }

        // if we do not swap
        if (nums1[index] > prev1 && nums2[index] > prev2) {
            ans = min(ans, solveMem (nums1, nums2, index + 1, 0, dp));
        }

        return dp[index][swapped] = ans;
    }

    int solveTab (vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp (n+1, vector<int> (2, 0));

        for (int index = n-1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // here is the main catch of the code
                if (swapped) {
                    swap (prev1, prev2);
                }

                // if we decide to swap
                if (nums1[index] > prev2 && nums2[index] > prev1) {
                    ans = min (ans, 1 + dp[index + 1][1]);
                }

                // if we do not swap
                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = min(ans,dp[index + 1][0]);
                }

                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];
    }

    int solveTabSO (vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int swapE = 0;
        int noswap = 0;

        int currSwap = 0;
        int currNoSwap = 0;

        for (int index = n-1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // here is the main catch of the code
                if (swapped) {
                    swap (prev1, prev2);
                }

                // if we decide to swap
                if (nums1[index] > prev2 && nums2[index] > prev1) {
                    ans = min (ans, 1 + swapE);
                }

                // if we do not swap
                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = min(ans, noswap);
                }

                if (swapped) {
                    currSwap = ans;
                }
                else {
                    currNoSwap = ans;
                }
            }

            swapE = currSwap;
            noswap = currNoSwap;
        }

        return min(swapE, noswap);
    }

public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // 1 -> Recursion
        // nums1.insert(nums1.begin(), -1);
        // nums2.insert(nums2.begin(), -1);
        // bool swapped = 0;
        // return solveRec (nums1, nums2, 1, swapped);

        // 2 -> Memoization
        // nums1.insert(nums1.begin(), -1);
        // nums2.insert(nums2.begin(), -1);

        // int n = nums1.size();

        // bool swapped = 0;
        // vector<vector<int>> dp (n+1, vector<int> (2, -1));

        // return solveMem (nums1, nums2, 1, swapped, dp);

        // 3 -> Tabulation
        // nums1.insert(nums1.begin(), -1);
        // nums2.insert(nums2.begin(), -1);
        // return solveTab (nums1, nums2);

        // 4 -> Space optimisation
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solveTabSO (nums1, nums2);
    }
};