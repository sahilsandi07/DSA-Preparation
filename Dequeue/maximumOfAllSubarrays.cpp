#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        // remove all out of bound indices
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }

        // maintain the decreasing order
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        // puh max element in the answer vector
        if (i >= k - 1)
        {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {-1,2,4,3,6,7,3,2,8,9};
    int k = 3;

    cout << "Original Array is: \n";

    for (auto it : nums)
    {
        cout << it << " ";
    }
    cout << endl;

    vector<int> ans = maxSlidingWindow(nums, k);

    cout << "Maximum Element in every SubArray of size k is :\n" ;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}