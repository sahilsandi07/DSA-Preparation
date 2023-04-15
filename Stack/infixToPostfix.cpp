class Solution
{
public:
    // Function to check if the given character is an operator or not.
    bool isOperator(char c)
    {
        return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-');
    }
    // Function to return the precedence of the given operator.
    int getPrecedence(char c)
    {
        if (c == '^')
        {
            return 3;
        }
        else if (c == '*' || c == '/')
        {
            return 2;
        }
        else if (c == '+' || c == '-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        stack<char> st;
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (isalnum(c))
            {
                res += c;
            }
            else if (c == '(')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && getPrecedence(c) <= getPrecedence(st.top()))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};