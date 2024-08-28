/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool check(TreeNode* root,TreeNode* target){
        if(root==NULL){
            return false;
        }
        
        if(target==root){
            return true;
        }

        return check(root->left,target)||check(root->right,target);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root; // base case

        bool isPLeft = check(root->left,p);
        bool isQLeft = check(root->left,q);

        if(isPLeft==isQLeft){
            // agar dono right me h right me recursive call kr do similarly for left
            if(isPLeft){
                // left me h
                return lowestCommonAncestor(root->left,p,q);
            }
            else{
                return lowestCommonAncestor(root->right,p,q);
            }
        }
        else{
            // agar ek right me h aur dusra left me h toh root hoga
            return root;
        }
    }
};
