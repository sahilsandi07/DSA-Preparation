#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

int sizeOfBT_recursive (Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return (1 + sizeOfBT_recursive(root->left) + sizeOfBT_recursive(root->right));
}

int sizeOfBT_iterative (Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int cnt = 0;

    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        cnt ++;

        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }

    return cnt;
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

    cout << "Height of Binary Tree Recursive: " << sizeOfBT_recursive (root) << endl;
    cout << "Height of Binary Tree Iterative: " << sizeOfBT_iterative (root) << endl;

    return 0;
}