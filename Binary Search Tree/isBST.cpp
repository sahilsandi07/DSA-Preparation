#include <iostream>
#include <climits>

using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Helper function to check if a subtree satisfies BST property
    bool isSubtreeBST(Node* root, int min_val, int max_val) {
        if (root == NULL) {
            return true;
        }
        if (root->data <= min_val || root->data >= max_val) {
            return false;
        }
        return isSubtreeBST(root->left, min_val, root->data) && 
               isSubtreeBST(root->right, root->data, max_val);
    }
    
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        return isSubtreeBST(root, INT_MIN, INT_MAX);
    }
};

int main() {
    // Create a sample binary tree that is not a BST
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(17);

    Solution solution;
    if (solution.isBST(root)) {
        cout << "The binary tree is a BST." << endl;
    }
    else {
        cout << "The binary tree is not a BST." << endl;
    }

    // Free memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
