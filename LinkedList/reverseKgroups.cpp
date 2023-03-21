#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    Node *getHead()
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

    Node *reverseGroup(Node *head, int k)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        int count = 0;

        // Reverse first k nodes of the linked list
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursively reverse the remaining nodes of the linked list
        if (next != NULL)
        {
            head->next = reverseGroup(next, k);
        }

        return prev;
    }

    void reverseInGroups(int k)
    {
        head = reverseGroup(head, k);
    }
};

int main()
{
    LinkedList list;

    list.add(10);
    list.add(9);
    list.add(8);
    list.add(7);
    list.add(6);
    list.add(5);
    list.add(4);
    list.add(3);
    list.add(2);
    list.add(1);

    int k = 3;

    cout << "Original Linked List is: \n";
    list.print();

    cout << "Linked List after Reversing in groups of " << k << " is:\n";
    list.reverseInGroups(k);
    list.print();
}
