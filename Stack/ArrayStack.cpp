#include <bits/stdc++.h>
using namespace std;

struct MyStack
{
    int* arr;
    int cap;
    int top;

    //MyStack Constructor
    MyStack (int c)
    {
        cap = c;
        arr = new int [cap];
        top = -1;
    }

    //Push Function of the Stack
    void push (int x)
    {
        if (top == cap - 1)
        {
            cout << "Stack is Full!" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    //Pop Function of the stack
    int pop ()
    {
        if (top == -1)
        {
            cout << "No Elemnt to Pop!" << endl;
            return 0;
        }
        int res = arr[top];
        top --;
        return res;
    }

    //Peek Function of the stack
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty!" << endl;
            return 0;
        }
        return arr[top];
    }

    //Size function of the stack
    int size()
    {
        return (top + 1);
    }

    //isEmpty function of the stack
    bool isEmpty()
    {
        return (top == -1);
    }
};

int main()
{
    MyStack st (6);

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