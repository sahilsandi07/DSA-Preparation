#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(int price[], int n)
{
    vector<int> span;
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        int days = 1;
        while (!st.empty() && st.top().first <= price[i])
        {
            days += st.top().second;
            st.pop();
        }

        st.push({price[i], days});
        span.push_back(days);
    }

    return span;
}

int main()
{
    int arr[] = {18, 12, 13, 14, 11, 16};
    int n = 6;
    vector<int> ans = calculateSpan(arr, n);
    for (auto it:  ans)
    {
        cout << it << " ";
    }
    return 0;
}
