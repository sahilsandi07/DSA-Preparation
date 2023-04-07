#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    Node* mergeTwoLists(Node* l1, Node* l2) 
    {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->data < l2->data) 
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } 
        else 
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    
    Node* mergeKLists(Node* arr[], int K) 
    {
        if (K == 0) return nullptr;
        int last = K - 1;
        while (last != 0) 
        {
            int i = 0, j = last;
            while (i < j) 
            {
                arr[i] = mergeTwoLists(arr[i], arr[j]);
                i++;
                j--;
                if (i >= j) last = j;
            }
        }
        return arr[0];
    }
};