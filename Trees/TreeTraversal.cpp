/*
    1. Breadth First (Level Order Traversal)

    2. Depth First
        2.1 Inorder Traversal (left subtree -> root -> right subtree)
        2.2 Preorder Traversal (root -> left subtree -> right subtree)
        2.3 Postorder Traversal (left subtree -> right subtree -> root)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        // hame pata hai ki inorder traversal me left, root aur right ko bulate hain
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(TreeNode *root)
{
    if (root != NULL)
    {
        // hame pata hai ki preorder traversal me root, left aur right ko bulate hain
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(TreeNode *root)
{
    if (root != NULL)
    {
        // hame pata hai ki postorder traversal me left, right aur root ko bulate hain
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    // Example binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Traversing the tree
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}