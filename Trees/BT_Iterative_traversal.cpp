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

void inorder(Node *root)
{
    stack<Node *> s;
    Node *current = root;
    while (!s.empty() || current != nullptr)
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->val << " ";
        current = current->right;
    }
    cout << endl;
}

void preorder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *current = s.top();
        s.pop();
        if (current != nullptr)
        {
            cout << current->val << " ";
            s.push(current->right);
            s.push(current->left);
        }
    }
    cout << endl;
}

void postorder(Node *root)
{
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        Node *current = s1.top();
        s1.pop();
        if (current != nullptr)
        {
            s2.push(current);
            s1.push(current->left);
            s1.push(current->right);
        }
    }
    while (!s2.empty())
    {
        Node *current = s2.top();
        s2.pop();
        cout << current->val << " ";
    }
    cout << endl;
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

    cout << "Inorder traversal: ";
    inorder(root);

    cout << "Preorder traversal: ";
    preorder(root);

    cout << "Postorder traversal: ";
    postorder(root);

    return 0;
}
