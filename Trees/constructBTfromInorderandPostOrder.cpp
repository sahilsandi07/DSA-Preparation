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

void printTree (Node* root)
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

int getPosition(vector<int> arr, Node* root)
{
    for (int i=0; i<arr.size(); i++)
    {
        if (arr[i] == root -> val)
        {
            return i;
        }
    }
    return -1;
}

Node* constructBT (vector<int> &inorder, vector<int> &postorder, int &index, int inorderStart, int inorderEnd, int n)
{
    // Base Case
    if (index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }
    Node* root = new Node(postorder[index--]);

    int pos = getPosition(inorder, root);

    // Recursive Calls
    root -> right = constructBT (inorder, postorder, index, pos + 1, inorderEnd, n);
    root -> left = constructBT (inorder, postorder, index, inorderStart, pos - 1, n);

    return root;
}

int main()
{
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    int n = postorder.size();
    int postOrderIndex = n-1;
    Node* root = constructBT(inorder, postorder, postOrderIndex, 0, n-1, n);
    printTree(root);

    return 0;
}