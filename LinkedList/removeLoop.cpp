class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node *current=head;
        Node *slow=head;
        Node *fast=head;
        if(head==NULL || head->next==NULL)
        {
            return;
        }
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        if(slow==head)
        {
            while(fast->next!=slow)
            {
                fast=fast->next;
            }
            fast->next=NULL;
        }
        else if(slow==fast)
        {
           slow=head;
           while(slow->next!=fast->next)
           {
               slow=slow->next;
               fast=fast->next;
           }
           fast->next=NULL;
        }
    }
};