#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void add(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        if (head != NULL) {
            head->prev = temp;
        }
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

    Node *delHead()
    {
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            Node *temp = head->next;
            delete head;
            head = temp;
            if (head != NULL) {
                head->prev = NULL;
            }
            return head;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    cout << "Original list: ";
    list.print();

    cout << "Deleting head node..." << endl;
    Node *newHead = list.delHead();

    cout << "New head node: " << newHead->data << endl;

    cout << "Updated list: ";
    list.print();

    return 0;
}
