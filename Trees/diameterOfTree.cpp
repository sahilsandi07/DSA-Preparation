#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        val = k;
        left = right = NULL;
    }
};

class Solution {
  public:
    pair<int, int> diaFast (Node* root)
    {
        //base case
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        
        //recursive calls for left and right subtrees
        pair<int, int> left = diaFast (root -> left);
        pair<int, int> right = diaFast (root -> right);
        
        //three different siameters
        int opt_1 = left.first;
        int opt_2 = right.first;
        int opt_3 = left.second + right.second + 1;
        
        //answer
        pair<int, int> ans;
        ans.first = max(opt_1, max(opt_2,opt_3));
        ans.second = max (left.second, right.second) + 1;
        
        
        return ans;
        
    }
    int diameter(Node* root) {
        return diaFast(root).first;
    }
};

int main()
{

    /*
     * Construct the following binary tree:
     *        10
     *      /   \
     *    20     30
     *    / \   / \
     *  40  50 60  70
     */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    
    Solution obj;

    cout << "The Maximum Diameter of the given Binary Tree is: " << obj.diameter(root) << endl;
    return 0;

}