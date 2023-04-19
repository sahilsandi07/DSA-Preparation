#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Function to reverse a queue
queue<int> reverseQueue(queue<int> q) 
{
    stack<int> st;

    // push all elements of the queue onto a stack
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    // pop all elements from the stack and enqueue them back into the queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    return q;
}

int main() {
    queue<int> q;

    // enqueue some elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // print the original queue
    cout << "Original queue: ";
    while (!q.empty()) {
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

    // reverse the queue and print the result
    queue<int> reversedQueue = reverseQueue(q);
    cout << "Reversed queue: ";
    while (!reversedQueue.empty()) {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }
    cout << endl;

    return 0;
}
