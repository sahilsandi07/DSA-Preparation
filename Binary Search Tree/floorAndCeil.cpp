#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node with given key
Node* newNode(int key) {
    Node* node = new Node;
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the floor of given key in BST
int floor(Node* root, int key) {
    Node* res = NULL;
    
    while (root != NULL) {
        if (root -> data == key) {
            // If the current node has the key value, return its data value
            return root -> data;
        } else if (root -> data > key) {
            // If the current node's data value is greater than the key value,
            // move to its left child
            root = root -> left;
        } else {
            // If the current node's data value is less than the key value,
            // update the result to the current node and move to its right child
            res = root;
            root = root -> right;
        }
    }
    
    // If we reach a leaf node without finding the key value, return the
    // data value of the last node visited with a data value less than the key value
    return res != NULL ? res->data : -1;
}

// Function to find the ceiling of given key in BST
int findCeil(Node* root, int input) {
    // If tree is empty, return -1
    if (root == NULL) return -1;
    
    Node* res = NULL;
    
    // Traverse the tree to find the ceiling
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

// Main function to test the code
int main() {
    // Create a sample BST
    Node* root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(10);
    root->right->right = newNode(14);
    
    // Test the floor and ceil functions
    int key = 5;
    cout << "Floor of " << key << " is: " << floor(root, key) << endl;
    
    key = 15;
    cout << "Ceiling of " << key << " is: " << findCeil(root, key) << endl;
    
    return 0;
}
