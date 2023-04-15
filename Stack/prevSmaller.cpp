vector<int> prevSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}