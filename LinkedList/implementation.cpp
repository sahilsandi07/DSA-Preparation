#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node (int x)
    {
        data = x;
        next = NULL;
    }
};

int main()
{
    Node *head = new Node (10);
    head -> next = new Node (20);
    head -> next -> next = new Node (30);
    head -> next -> next -> next = new Node (40);
    cout<<head->data<<" --> "<<head->next->data<<" --> "<<head->next->next->data;
    return 0;
}
