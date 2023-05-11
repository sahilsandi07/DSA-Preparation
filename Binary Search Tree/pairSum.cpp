// Initial Template for C++

// CPP program to find a pair with
// given sum using hashing
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


bool findPair(Node* root, int sum);

// Driver code
int main() {

    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n, x;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
        cin >> x;
        if (findPair(root, x))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}

bool findPairUtil(Node* node, int X, unordered_set<int>& s) 
{
    if (node == NULL)
        return false;

    if (findPairUtil(node->left, X, s))
        return true;

    if (s.find(X - node->data) != s.end())
        return true;

    s.insert(node->data);

    return findPairUtil(node->right, X, s);
}

bool findPair(Node* root, int X) 
{
    unordered_set<int> s;
    return findPairUtil(root, X, s);
}
