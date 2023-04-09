#include <bits/stdc++.h>
using namespace std;

struct MyStack
{
    vector<int> v;

    void push (int x)
    {
        v.push_back(x);
    }

    int pop()
    {
        int res = v.back();
        v.pop_back();
        return res;
    }

    int size()
    {
        return v.size();
    }

    bool isEmpty()
    {
        return v.empty();
    }

    int peek()
    {
        return v.back();
    }
};

int main()
{
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout << st.pop() << endl;
    cout << st.size() << endl;
    cout << st.peek() << endl;
    cout << (st.isEmpty() ? "Stack is Empty!" : "Stack is Not Empty!") << endl;
}