#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    Node* merge(Node* left, Node* right) 
    {
        if (!left) return right;
        if (!right) return left;
        if (left->data < right->data) 
        {
            left->next = merge(left->next, right);
            return left;
        } 
        else 
        {
            right->next = merge(left, right->next);
            return right;
        }
    }
    
    Node* getMiddle(Node* head) {
        Node *slow = head, *fast = head;
        while (fast->next && fast->next->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* middle = slow->next;
        slow->next = nullptr;
        return middle;
    }
    
    Node* mergeSort(Node* head) 
    {
        if (!head || !head->next) return head;
        Node* middle = getMiddle(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(middle);
        return merge(left, right);
    }
};