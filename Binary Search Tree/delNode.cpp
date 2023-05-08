#include <iostream>
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

void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: No children or Case 2: One child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 3: Two children
        Node* successor = root->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    
    return root;
}

int main() {
    Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);
    
    cout << "Inorder traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;
    
    int key = 30;
    root = deleteNode(root, key);
    
    cout << "Inorder traversal after deletion of " << key << ": ";
    inorderTraversal(root);
    cout << endl;
    
    key = 50;
    root = deleteNode(root, key);
    
    cout << "Inorder traversal after deletion of " << key << ": ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}
