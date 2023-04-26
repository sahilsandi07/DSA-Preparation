#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

int maxOfBT_recursive (Node* root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    return max(root->val, max(maxOfBT_recursive(root->left) , maxOfBT_recursive(root->right)));
}

int maxOfBT_iterative (Node* root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    queue<Node*> q;
    q.push(root);
    int maxOfBT = INT_MIN;

    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        maxOfBT = max (maxOfBT, curr->val);

        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }

    return maxOfBT;
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

    cout << "Max of Binary Tree Recursive: " << maxOfBT_recursive (root) << endl;
    cout << "Max of Binary Tree Iterative: " << maxOfBT_iterative (root) << endl;

    return 0;
}