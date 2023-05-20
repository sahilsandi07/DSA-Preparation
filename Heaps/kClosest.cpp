#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    vector<int> arr = {12, 2, 4, 34, 45, 56, 13, 14};
    int n = arr.size();
    int x = 20;
    int k = 4;

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push({abs(arr[i] - x), i});
    }

    for (int i = k; i < n; i++)
    {
        int diff = abs(arr[i] - x);

        if (diff < pq.top().first)
        {
            pq.pop();
            pq.push({diff, i});
        }
    }

    while (k--)
    {
        cout << arr[pq.top().second] << endl;
        pq.pop();
    }

    return 0;
}
