// ex:  i/p: 1 -> 2 -> 3 -> 4 -> 5
// we have to insert 6 in such a away that the LL remains sorted.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
    private:
    Node* head;

    public:
    LinkedList()
    {
        head = NULL;
    }

    Node *getHead() // public getter method to access the head pointer
    {
        return head;
    }

    void add(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* sortedInsert (Node* head, int x)
    {
        Node* temp = new Node(x);
        if (head == NULL)   return temp;

        if (x < head->data)
        {
            temp->next = head;
            return temp;
        }

        Node* curr = head;
        while (curr->next != NULL && curr->next->data < x)
        {
            curr = curr->next;
        }

        temp->next = curr->next;
        curr->next = temp;

        return head;
    }
};

int main()
{
    LinkedList lists;

    lists.add(5);
    lists.add(6);
    lists.add(8);
    lists.add(9);
    lists.add(11);
    lists.add(13);
    lists.add(15);
    
    Node* head = lists.getHead();
    lists.sortedInsert(head, 10);
    lists.print();
}