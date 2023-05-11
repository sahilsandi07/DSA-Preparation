vector<int> levelOrder(struct Node* root) {
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue <Node*> q;
    q.push(root);
    
    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        
        ans.push_back(curr -> data);
        
        if (curr -> left)   q.push(curr -> left);
        if (curr -> right)  q.push(curr -> right);
    }
    return ans;
}