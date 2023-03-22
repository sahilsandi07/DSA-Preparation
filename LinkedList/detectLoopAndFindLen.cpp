#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

int countNodesinLoop(struct Node *head)
{
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
        {
            break;
        }
    }
    
    if (slow != fast)
    {
        return 0;
    }
    
    int cnt = 1;
    fast = fast->next;
    while (slow != fast)
    {
        cnt ++;
        fast = fast->next;
    }
    
    return cnt;
}

int main() 
{ 
	Node *head=new Node(15);
	head->next=new Node(10);
	head->next->next=new Node(12);
	head->next->next->next=new Node(20);
	head->next->next->next->next=head->next;
	if (countNodesinLoop(head) == 0) 
        cout << "No Loop found" << endl; 
    else
        cout << "Loop Exists!\n";
        cout << "Length of Loops is: " << countNodesinLoop(head) << endl; 
	return 0;
} 
