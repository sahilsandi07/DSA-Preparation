#include<bits/stdc++.h>
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

class Solution
{
    public:
    Node* mergeTwoLists (Node* a, Node* b)
    {
        if (a == NULL)
        {
            return b;
        }
        if (b == NULL)
        {
            return a;
        }

        Node* head = NULL;
        Node* tail = NULL;

        if (a->data < b->data)
        {
            head = tail = a;
            a= a->next;
        }
        else 
        {
            head = tail = b;
            b = b->next;
        }

        while (a != NULL && b != NULL)
        {
            if (a->data <= b->data)
            {
                tail->next = a;
                tail = a;
                a = a->next;
            }
            else 
            {
                tail->next = b;
                tail = b;
                b = b->next;
            }
        }

        if (a == NULL)
        {
            tail->next = b;
        }
        else 
        {
            tail->next = a;
        }
        return head;
    }   
};

int main() {
    // create the first linked list: 1->2->4
    Node* l1 = new Node(1);
    l1->next = new Node(2);
    l1->next->next = new Node(4);
    
    // create the second linked list: 1->3->4
    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);
    
    // merge the two linked lists
    Solution solution;
    Node* mergedList = solution.mergeTwoLists(l1, l2);
    
    // print the merged linked list
    cout << "Printing the sorted list after Merging two sorted lists.\n";
    while (mergedList) {
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }
    
    return 0;
}