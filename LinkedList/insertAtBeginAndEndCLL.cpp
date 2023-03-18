#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *insertAtBegin(Node *head, int x)
{
    Node *temp = new Node(x);

    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }

    else
    {
        temp->next = head->next; // Insert after head
        head->next = temp;

        int t = head->data; // Swap Head with Element
        head->data = temp->data;
        temp->data = t;

        return head;
    }
}

Node *insertAtEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;

        int t = head->data;
        head->data = temp->data;
        temp->data = t;

        return temp;
    }
}

void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *p = head;

    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;

    cout << "Inserting At Begin......\n";
    head = insertAtBegin(head, 7);
    print(head);
    cout << endl;

    cout << "Inserting At End......\n";
    head = insertAtEnd(head, 9);
    print(head);
    cout << endl;
    return 0;
}
