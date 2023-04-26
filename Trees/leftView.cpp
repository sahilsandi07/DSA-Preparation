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

void printLeft (Node* root)
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
            if (i == 0)
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
    }
}

int main()
{

    /*
     * Construct the following binary tree:
     *        10
     *      /   \
     *    20     30
     *    / \   / \
     *  40  50 60  70
     */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    root->right->left->left = new Node(60);


    printLeft(root);
}