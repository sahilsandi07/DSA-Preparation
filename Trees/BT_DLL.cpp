#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};
Node *BTToDLL(Node *root)
{
    if (root == NULL)
        return root;
    static Node *prev = NULL;
    Node *head = BTToDLL(root->left);
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTToDLL(root->right);
    return head;
}

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    Node *head = BTToDLL(root);
    printlist(head);

    return 0;
}