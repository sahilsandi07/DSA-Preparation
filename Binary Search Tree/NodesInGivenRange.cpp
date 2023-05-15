#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function to count number of nodes in BST that lie in the given range.
class Solution
{
private:
    // Inorder Traversal of BST
    void inorder(Node *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    // Getcount function to check elements in the given ranges
    int getCnt(vector<int> &arr, int &l, int &h)
    {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= l and arr[i] <= h)
            {
                cnt++;
            }
        }
        return cnt;
    }

public:
    int getCount(Node *root, int l, int h)
    {
        vector<int> arr;
        inorder(root, arr);
        return getCnt(arr, l, h);
    }
};


int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin >> ws, s);
        int l, r;
        cin >> l >> r;
        Solution ob;
        Node *root = buildTree(s);
        cout << ob.getCount(root, l, r) << endl;
    }
    return 1;
}
