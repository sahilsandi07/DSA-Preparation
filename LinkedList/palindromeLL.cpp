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

    Node* revLL (Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL)
        {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome (Node* head)
    {
        if (head == NULL)
        {
            return true;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* rev =  revLL(slow->next);
        Node* curr = head;
        while (rev != NULL)
        {
            if (rev->data != curr->data)
            {
                revLL(slow->next);
                return false;
            }

            rev = rev->next;
            curr = curr->next;
        }
        revLL(slow->next);
        return true;
    }
};

int main()
{
    solve obj;

    cout << "Enter Number of elements in List: " << endl;
    int n; 
    cin >> n;
    cout << "Enter elemnets: " << endl;
    while (n--)
    {
        int x;
        cin >> x;
        obj.add(x);
    }

    // obj.add(1);
    // obj.add(2);
    // obj.add(3);
    // obj.add(4);
    // obj.add(5);
    // obj.add(4);
    // obj.add(3);
    // obj.add(2);
    // obj.add(1);

    Node* head = obj.getHead();
    cout << "Given Linked List is: \n";
    obj.print();

    if (obj.isPalindrome(head))
    {
        cout << "The Given Linked List is Palindrome!" << endl;
    }
    else
    {
        cout << "The Given List is Not Palindrome!" << endl;
    }
}