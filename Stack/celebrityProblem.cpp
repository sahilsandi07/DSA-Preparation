class Solution
{
private:
    bool knows(vector<vector<int>> &M, int A, int B, int n)
    {
        if (M[A][B] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        // push all elements in the stack
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        // remove two elements from stack and check who knows whom
        while (st.size() > 1)
        {
            int A = st.top();
            st.pop();

            int B = st.top();
            st.pop();

            if (knows(M, A, B, n))
            {
                st.push(B);
            }
            else
            {
                st.push(A);
            }
        }
        int candidate = st.top();

        // The element at the top of the stack is the potential candidate for being a celebrity
        // verify candidacy of the top element
        int zeroCnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[candidate][i] == 0)
            {
                zeroCnt++;
            }
        }

        if (zeroCnt != n)
        {
            return -1;
        }

        int oneCnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][candidate] == 1)
            {
                oneCnt++;
            }
        }

        if (oneCnt != n - 1)
        {
            return -1;
        }

        return candidate;
    }
};

int main()
{
    // create a 2D vector representing the relationships between people
    vector<vector<int>> M = {{0, 1, 1, 0},
                             {0, 0, 1, 0},
                             {0, 0, 0, 0},
                             {0, 0, 1, 0}};

    Solution s;
    int celebrity = s.celebrity(M, 4);
    if (celebrity == -1)
    {
        cout << "There is no celebrity in the group." << endl;
    }
    else
    {
        cout << "The celebrity is person " << celebrity << "." << endl;
    }

    return 0;
}