#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    void add(int x) // insert elements in the linked list
    {
        Node *temp = new Node(x);
        if (head == nullptr) {
            head = temp;
            head->next = head;
        }
        else {
            Node *p = head;
            while (p->next != head) {
                p = p->next;
            }
            p->next = temp;
            temp->next = head;
        }
    }

    void print() // print the elements in the linked list
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *p = head;

        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }

    Node *getHead() // public getter method to access the head pointer
    {
        return head;
    }

    Node *delHead() // delete the head node
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return nullptr;
        }

        if (head->next == head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            Node *p = head;
            while (p->next != head) {
                p = p->next;
            }
            head = head->next;
            p->next = head;
            delete temp;
        }
        return head;
    }

    Node *delKth(int k) // delete the kth node from the linked list
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return nullptr;
        }

        if (k == 1)
        {
            return delHead();
        }

        Node *curr = head;
        for (int i = 0; i < k - 2; i++)
        {
            curr = curr->next;
        }

        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }
};

int main()
{
    CircularLinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);

    cout << "Initial list: ";
    list.print();

    list.delKth(4);
    cout << "List after deleting K'th node: ";
    list.print();

    return 0;
}
