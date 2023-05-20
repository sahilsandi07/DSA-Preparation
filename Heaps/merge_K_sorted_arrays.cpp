#include <bits/stdc++.h>
using namespace std;

// Class representing the data element
class data
{
public:
    int val, array_pos, value_pos;

    data(int v, int ap, int vp)
    {
        val = v;
        array_pos = ap;
        value_pos = vp;
    }
};

// Comparator struct for the priority queue
struct cmp
{
    bool operator()(data &d1, data &d2)
    {
        return (d1.val > d2.val); // Comparison based on the value
    }
};

class Solution
{
public:
    vector<int> mergeKSorted(vector<vector<int>> arr, int k)
    {
        vector<int> ans;

        priority_queue<data, vector<data>, cmp> pq; // Priority queue to store the minimum element
        for (int i = 0; i < k; i++)
        {
            data d(arr[i][0], i, 0); // Create data object with initial element of each array
            pq.push(d);              // Push the data object into the priority queue
        }

        while (!pq.empty())
        {
            data curr = pq.top(); // Get the minimum element from the priority queue
            pq.pop();
            ans.push_back(curr.val); // Add the minimum element to the result

            int ap = curr.array_pos;
            int vp = curr.value_pos;

            if (vp + 1 < arr[ap].size()) // Check if there are more elements in the current array
            {
                data d(arr[ap][vp + 1], ap, vp + 1); // Create a new data object with the next element from the current array
                pq.push(d);                          // Push the new data object into the priority queue
            }
        }

        return ans;
    }
};

class Solution2
{
public:
    vector<int> mergeKSorted(vector<vector<int>> &arr, int k)
    {
        vector<int> ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < k; i++)
        {
            pq.push({arr[i][0], {i, 0}});
        }

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int val = curr.first;
            int array_pos = curr.second.first;
            int value_pos = curr.second.second;

            ans.push_back(val);

            if (value_pos + 1 < arr[array_pos].size())
            {
                pq.push({arr[array_pos][value_pos + 1], {array_pos, value_pos + 1}});
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 7}, {6, 8, 9, 11}};
    int k = 3;

    Solution obj;
    vector<int> ans = obj.mergeKSorted(arr, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    Solution2 obj2;
    vector<int> ans2 = obj2.mergeKSorted(arr, k);

    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
    cout << endl;

    return 0;
}
