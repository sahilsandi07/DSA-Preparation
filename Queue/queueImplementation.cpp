#include<bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int qFront;
    int rear;
    int size;

    public:

    Queue()
    {
        size = 100001;
        arr = new int[size];
        qFront = 0; 
        rear = 0;
    }

    bool isEmpty()
    {
        if (qFront == rear)
        {
            return true;
        }

        else{
            return false;
        }
    }

    void enqueue (int data)
    {
        if (rear == size)
        {
            cout << "Queue is Full!\n";
        }

        else 
        {
            arr[rear] = data;
            rear ++;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            int ans = arr[qFront];
            arr[qFront] = -1;
            qFront ++;
            if (qFront == rear)
            {
                qFront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    void front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!\n";
        }
        else
        {
            cout << arr[qFront] << endl;
        }
    }

    void print()
    {
        cout << "Elements in the Queue are : \n";
        for (int i=0; i<rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.print();

    q.dequeue();
    q.print();
    q.front();
    q.enqueue(80);

    q.dequeue();
    q.print();
    q.front();
    q.enqueue(90);
    
    q.dequeue();
    q.print();
    q.front();

    cout << (q.isEmpty() ? "Queue is Empty!" : "Queue is Not Empty!") << endl;
}