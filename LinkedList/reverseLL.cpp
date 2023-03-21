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

class solve
{
private:
    Node *head;

public:
    solve()
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

    void reverseLL()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        Node *curr = head;
        Node *prev = NULL;
        Node *forward = NULL;

        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        head = prev;
    }
};

int main()
{
    solve obj;

    obj.add(1);
    obj.add(2);
    obj.add(4);
    obj.add(5);
    obj.add(6);
    obj.add(7);
    obj.add(8);
    obj.add(9);
    obj.add(10);

    Node *head = obj.getHead();

    cout << "Original Linked List is: \n";
    obj.print();

    cout << "Linked List after Reversing is:\n";
    obj.reverseLL(); // Reverse the linked list
    obj.print(); // Print the reversed linked list
}
