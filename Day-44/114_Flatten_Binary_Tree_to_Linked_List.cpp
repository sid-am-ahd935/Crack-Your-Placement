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
    void flatten(TreeNode* root) {
        if(!root) return;

        // preorder traversal vector
        vector<TreeNode*> preorder;
        preOrder(root, preorder);

       // create the linked list
       for(int i = 1; i < preorder.size(); i++) {
        root->left = nullptr;
        root->right = preorder[i];
        root = root->right;
       }
    }

    void preOrder(TreeNode* root, vector<TreeNode*>& vec) {
        if(!root) {
             return;
        }
        vec.push_back(root);
        preOrder(root->left, vec);
        preOrder(root->right, vec);     
    }
};
