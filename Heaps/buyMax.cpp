#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int arr[n] = {12,1,2,5,4};
    int sum = 6;
    int res = 0;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i=0; i<n; i++)
    {
        pq.push(arr[i]);
    }
    for (int i=0; i<n; i++)
    {
        if (pq.top() <= sum)
        {
            sum -= pq.top();
            pq.pop();
            res++;
        }
        else {
            break;
        }
    }
    cout << res;
    return 0;
}