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

class solve
{
    private:
    Node* head;

    public:
    solve()
    {
        head = NULL;
    }

    Node* getHead()
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

    Node* removeDups (Node* head)
    {
        Node* curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            if (curr->data == curr->next->data)
            {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }

            else 
            {
                curr = curr->next;
            }
        }

        return head;
    }
};

int main()
{
    solve obj;

    obj.add(1);
    obj.add(2);
    obj.add(2);
    obj.add(3);
    obj.add(3);
    obj.add(3);
    obj.add(4);
    obj.add(5);
    obj.add(6);

    Node* head = obj.getHead();

    cout << "Original Linked List is: \n";
    obj.print();

    cout << "Linked List after removing Duplicates is:\n" ;
    obj.removeDups(head);
    obj.print();
}