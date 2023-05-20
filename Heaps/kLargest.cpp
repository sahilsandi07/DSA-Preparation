#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {12, 2, 34, 11, 14, 18, 1000};
    int n = arr.size();
    int k = 3;

    priority_queue<int, vector<int>, greater<int>> pq;

    // for (int i=0; i<n; i++)
    // {
    //     pq.push(arr[i]);
    // }

    // while (k--)
    // {
    //     cout << pq.top() << endl;
    //     pq.pop();
    // }

    for (int i=0; i<k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i=k ; i<n; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.push(arr[i]);
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}