/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checker(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr) 
            return true;;
        if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) ) 
            return false;
        if(p->val != q->val) 
            return false;

        bool p_tree = checker(p->left, q->left);
        bool q_tree = checker(p->right, q->right);

        if(p_tree == false || q_tree == false) 
            return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checker(p,q);
    }
};
