void solve(Node* root, int low, int high, int &count) {
    if (root == NULL) return;
    
    // Only check the left subtree if the current node's data is greater than low
    if (root->data > low) {
        solve(root->left, low, high, count);
    }
    
    // Check the current node's value
    if (root->data >= low && root->data <= high) {
        count++;
    }
    
    // Only check the right subtree if the current node's data is less than high
    if (root->data < high) {
        solve(root->right, low, high, count);
    }
}

int getCount(Node *root, int l, int h) {
    int count = 0;
    solve(root, l, h, count);
    return count;
}
