#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(int arr[], int n)
{
    stack<int> st;
    st.push(arr[n-1]);
    vector<int> ans;
    ans.push_back(-1);

    for (int i=n-2; i>=0;  i--)
    {
        while (st.empty() == false && st.top() <= arr[i])
        {
            st.pop();
        }
        
        int nextG = st.empty() ? -1 : st.top();

        ans.push_back(nextG);

        st.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int arr[] = {10,5,12,13,15,18};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> res = nextGreater(arr, n);

    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}