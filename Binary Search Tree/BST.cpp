#include <iostream>
using namespace std;

// Definition for a BST node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to search for a node in a BST
bool search(Node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }
    if (val < root->data)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

// Function to find the minimum element in a BST
int findMin(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

// Function to insert a node in a BST
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

// Driver code
int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Minimum element in BST: " << findMin(root) << endl;

    int val = 30;
    if (search(root, val))
    {
        cout << val << " found in BST" << endl;
    }
    else
    {
        cout << val << " not found in BST" << endl;
    }

    val = 10;
    if (search(root, val))
    {
        cout << val << " found in BST" << endl;
    }
    else
    {
        cout << val << " not found in BST" << endl;
    }

    root = insert(root, 55);
    cout << "After inserting 55, minimum element in BST: " << findMin(root) << endl;

    return 0;
}
