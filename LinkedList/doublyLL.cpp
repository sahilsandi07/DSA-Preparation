#include <bits/stdc++.h>
using namespace std;

#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Add a node at the end of the list
    void add(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        if (head == nullptr)
        {
            // Empty list
            new_node->prev = nullptr;
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Print all nodes
    void print()
    {
        Node *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.add(1);
    list.add(2);
    list.add(3);

    list.print();

    return 0;
}
