class Solution {
public:
    bool helper(TreeNode* root,int sum){
        if(root==NULL) return false;
        // this condition specify that we are in leaf node.because right & left of leaf node is NULL 
        if(root->left==NULL && root->right==NULL){
            if(root->val==sum) return true;
            else return false;
        }
        // Recursively call the helper function for left and right subtrees
        return helper(root->left,sum-root->val) || helper(root->right,sum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum);
    }
};
