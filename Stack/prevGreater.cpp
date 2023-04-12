#include <bits/stdc++.h>
using namespace std;

void prevGreater(int arr[], int n)
{
    stack<int> st;
    st.push(arr[0]);
    cout << -1 << " ";

    for (int i=1; i<n;  i++)
    {
        while (st.empty() == false && st.top() <= arr[i])
        {
            st.pop();
        }
        
        int prevG = st.empty() ? -1 : st.top();

        cout << prevG << " ";

        st.push(arr[i]);
    }
}

int main()
{
    int arr[] = {10,5,12,13,15,18};
    int n = sizeof(arr)/sizeof(arr[0]);

    prevGreater(arr, n);
    return 0;
}