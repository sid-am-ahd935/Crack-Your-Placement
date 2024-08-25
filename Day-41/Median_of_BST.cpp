/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
void inorder(Node* root, vector<int>& nums) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, nums);
    nums.push_back(root->data);
    inorder(root->right, nums);
}

float findMedian(Node* root) {
    vector<int> nums;
    inorder(root, nums);
    
    int n = nums.size();
    
    if (n == 0) {
        return 0.0;
    }
    
    if (n % 2 == 1) {
        int x = n / 2;
        return nums[x];
    } else {
        int x = n / 2;
        int y = x - 1;
        return (nums[x] + nums[y]) / 2.0;
    }
}
