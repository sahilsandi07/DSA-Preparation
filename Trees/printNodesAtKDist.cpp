#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void printNodesAtK (Node* root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->val << " ";
    }
    else
    {
        printNodesAtK(root->left, k-1);
        printNodesAtK(root->right, k-1);
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

    printNodesAtK (root, 2);

    return 0;
}
