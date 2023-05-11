//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

Node *constructBst(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

Node *constructBst(int arr[], int n)
{
    // Code here
    if (n <= 0)
        return NULL;
    Node *root = new Node(arr[0]);
    queue<pair<Node *, pair<int, int>>> q;
    q.push({root, {INT_MIN, INT_MAX}});

    int i = 1;
    while (!q.empty() && i < n)
    {
        Node *tmp = q.front().first;
        int low = q.front().second.first;
        int high = q.front().second.second;
        q.pop();

        if (arr[i] > low && arr[i] < tmp->data)
        {
            tmp->left = new Node(arr[i]);
            q.push({tmp->left, {low, tmp->data}});
            ++i;
        }
        else
            tmp->left = NULL;

        if (arr[i] > tmp->data && arr[i] < high)
        {
            tmp->right = new Node(arr[i]);
            q.push({tmp->right, {tmp->data, high}});
            ++i;
        }
        else
            tmp->right = NULL;
    }
    return root;
}