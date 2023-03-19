// Given a Linked List, We have to find the n'th node from the end.
// ex: 1 -> 2 -> 3 -> 4 -> 5 -> 6  and  lets say n=2
// therefore the 2'nd node from the last is 5.

// we have to find the middle element of the linkedlist
// ex: 1 -> 2 -> 3 -> 4 -> 5
// Here the middle element is 3.
// So we return Node 3. 

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

    void nthNode (Node* head, int n)
    {
        if (head == NULL)
        {
            return;
        }

        Node* fast = head; 
        Node* slow = head;

        for (int i=0; i<n; i++)
        {
            if (fast == NULL)
            {
                return;
            }

            fast = fast->next;
        }
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        cout << "The N'th node from the end of the Linked List is: " << slow->data ;
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
    cout << "Printing Main List....\n";
    lists.print();
    lists.nthNode(head, 2);
}