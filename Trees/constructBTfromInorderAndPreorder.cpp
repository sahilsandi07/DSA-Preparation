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

Node* constructBT (vector<int> &inorder, vector<int> &preorder, int &index, int inorderStart, int inorderEnd, int n)
{
    // Base Case
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }
    Node* root = new Node(preorder[index++]);

    int pos = getPosition(inorder, root);

    // Recursive Calls
    root -> left = constructBT (inorder, preorder, index, inorderStart, pos - 1, n);
    root -> right = constructBT (inorder, preorder, index, pos + 1, inorderEnd, n);

    return root;
}

int main()
{
    vector<int> inorder = {20,10,40,30,50};
    vector<int> preorder = {10,20,30,40,50};

    int n = preorder.size();
    int preOrderIndex = 0;
    Node* root = constructBT(inorder, preorder, preOrderIndex, 0, n-1, n);
    printTree(root);

    return 0;
}