#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int key) {
    Node* node = new Node;
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int floor(Node* root, int key) {
    vector<int> levelOrder;
    
    if (root == NULL)
    {
        return -1;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        
        levelOrder.push_back(curr -> data);
        
        if (curr -> left)
        {
            q.push(curr -> left);
        }
        if (curr -> right)
        {
            q.push(curr -> right);
        }
    }
    
    sort (levelOrder.begin(), levelOrder.end());
    
    for (int i=0; i<levelOrder.size(); i++)
    {
        if (levelOrder[i] == key)
        {
            return levelOrder[i];
        }
        else if (levelOrder[i] > key)
        {
            return levelOrder[i-1];
        }
        else
        {
            return -1;
        }
    }
}

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    Node* res = NULL;
    
    while (root != NULL)
    {
        if (root -> data == input)
        {
            return root -> data;
        }
        
        else if (root -> data > input)
        {
            res = root;
            root = root -> left;
        }
        
        else
        {
            root = root -> right;
        }
    }
    
    return root != NULL ? res -> data : -1;
}

int main() {
    Node* root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(10);
    root->right->right = newNode(14);
    
    int key = 5;
    cout << "Floor of " << key << " is: " << floor(root, key) << endl;
    
    key = 15;
    cout << "Ceiling of " << key << " is: " << findCeil(root, key) << endl;
    
    return 0;
}
