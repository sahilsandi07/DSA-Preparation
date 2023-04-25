#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void method1(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << curr->key << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

void method2 (Node* root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int cnt = q.size();

        for (int i=0; i<cnt; i++)
        {
            Node* curr = q.front();
            q.pop();
            cout << curr->key << " ";

            if (curr -> left != NULL)
            {
                q.push(curr -> left);
            }

            if (curr -> right != NULL)
            {
                q.push(curr -> right);
            }
        }

        cout << "\n";
    }
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

    cout << "Printing Level Order Line By Line By Method1: \n";
    method1(root);
    cout << "\n";
    cout << "Printing Level Order Line By Line By Method2: \n";
    method2(root);
}