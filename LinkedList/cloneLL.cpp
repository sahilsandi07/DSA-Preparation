#include <bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void insertAtTail (Node* &head, Node* &tail, int d)
    {
        Node* newNode = new Node (d);
        
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //Step 1: Create a Clone
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while (temp != NULL)
        {
            insertAtTail (cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        //Step 2: create a map
        unordered_map<Node*, Node*> oldToNewNode;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while (originalNode != NULL && cloneNode != NULL)
        {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        
        while (originalNode != NULL && cloneNode != NULL)
        {
            cloneNode->arb = oldToNewNode[originalNode->arb];
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
        
        return cloneHead;
    }

};