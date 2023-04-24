#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void levelOrder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        cout << curr->val << " ";
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

int main()
{
    /*
     * Construct the following binary tree:
     *        1
     *      /   \
     *     2     3
     *    / \   / \
     *   4   5 6   7
     */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    levelOrder (root);

    return 0;
}
