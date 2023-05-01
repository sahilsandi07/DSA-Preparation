#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

int widthOfBinaryTree (Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int width = 0;

    while (!q.empty())
    {
        int size = q.size();
        width = max(width, size);

        for (int i=0; i<size; i++)
        {
            Node* curr = q.front();
            q.pop();

            if (curr -> left)
            {
                q.push(curr -> left);
            }
            if (curr -> right)
            {
                q.push(curr -> right);
            }
        }
    }

    return width;
}

int main()
{
    Node* root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right -> left = new Node(60);
    root -> right -> right = new Node(70);

    cout << "Maximum Width of the Given Binary Tree is: " << widthOfBinaryTree(root) << endl;

    return 0;
}