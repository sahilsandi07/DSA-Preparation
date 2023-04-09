#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node (int x)
    {
        data = x;
        next = NULL;
    }
};

struct MyStack
{
    Node* head;
    int sz;

    MyStack()
    {
        head = NULL;
        sz = 0;
    }

    void push(int x)
    {
        Node* temp = new Node (x);
        temp->next = head;
        head = temp;
        sz++;
    }

    int pop()
    {
        if (head == NULL)
        {
            return INT_MAX;
        }

        int res = head->data;
        Node* temp = head;
        head = head->next;
        delete (temp);
        sz--;
        return res;
    }

    int size()
    {
        return sz;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    int peek()
    {
        if (head == NULL)
        {
            return INT_MAX;
        }

        return head->data;
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