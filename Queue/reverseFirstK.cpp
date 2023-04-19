#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    if (k <= 0 || k > q.size())
    {
        // invalid value of k, return the original queue
        return q;
    }

    stack<int> st;

    // reverse the first k elements using a stack
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // enqueue the reversed elements back into the queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // move the remaining elements to the back of the queue
    for (int i = 0; i < q.size() - k; i++)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }

    return q;
}

int main()
{
    int k = 3;
    queue<int> q;

    // enqueue some elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // print the original queue
    cout << "Original queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // enqueue the elements back into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // modify the queue and print the result
    queue<int> modifiedQueue = modifyQueue(q, k);
    cout << "Modified queue: ";
    while (!modifiedQueue.empty())
    {
        cout << modifiedQueue.front() << " ";
        modifiedQueue.pop();
    }
    cout << endl;

    return 0;
}
