class Solution {
private:
    vector<int> nextSmaller (vector<int> arr, int n)
    {
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for (int i=n-1; i>=0; i--)
        {
            int curr = arr[i];

            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }

            ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmaller (vector<int> arr, int n)
    {
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for (int i=0; i<n; i++)
        {
            int curr = arr[i];

            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }

            ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmaller(heights, n);

        vector<int> prev(n);
        prev = prevSmaller(heights, n);

        int area = INT_MIN;
        for (int i=0; i<n; i++)
        {
            int length = heights[i];

            if (next[i] == -1)
            {
                next[i] = n;
            }
            int breadth = next[i] - prev[i] - 1;

            int newArea = length*breadth;

            area = max(area, newArea); 
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int maxi = INT_MIN;
        vector<int> histogram(matrix[0].size(), 0);

        for (int i=0; i<matrix.size(); i++)
        {
            for (int j=0; j<histogram.size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    histogram[j] ++;
                }
                else
                {
                    histogram[j] = 0;
                }
            }

            maxi = max(maxi, largestRectangleArea(histogram));
        }

        return maxi;
    }
};