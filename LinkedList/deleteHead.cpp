#include <iostream>
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
            return head;
        }
    }
};

int main()
{
    LinkedList list;
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
