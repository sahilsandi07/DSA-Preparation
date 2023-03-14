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

class LinkedList
{
    private:
    Node *head;

    public:
    LinkedList()
    {
        head = NULL;
    }

    void add(int x)                     //insert elements in the linked list
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
    }

    void print()                        //print element in the linked list
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getHead()                     //public getter method to access the head pointer
    {
        return head;
    }

    //Iterative Approach to search in a Linked List

    void search(Node *head, int element)
    {
        int pos = 1;
        Node *curr = head;

        while (curr != NULL)
        {
            if (curr->data == element)
            {
                cout << "Found Element " << element << " at position " << pos << endl;
                return;
            }

            pos ++;
            curr = curr->next;
        }

        cout << "Element Not Found in the Linked List." << endl;
    }

    // Recursive Approach to Search the Element

    int searchRec(Node *head, int element)
    {
        if (head == NULL)
        {
            return -1;
        }

        if (head -> data == element)
        {
            return 1;
        }

        else
        {
            int res = searchRec(head -> next, element);
            if (res == -1)
            {
                return -1;
            }
            else
            {
                return res+1;
            }
        }
    }
};

int main()
{
    LinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);

    cout << "Original list: ";
    list.print();

    cout << "Iterative Search Result is: ";
    list.search(list.getHead(), 30);

    cout << "Recursive Search Result is: ";
    int res = list.searchRec(list.getHead(), 40);
    if (res == -1)
    {
        cout << "Element not found." << endl;
    }
    else
    {
        cout << "Element found at position " << res << endl;
    }
    return 0;
}
