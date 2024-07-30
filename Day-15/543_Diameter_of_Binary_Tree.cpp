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
private:
    int getD(TreeNode* root, int& ans, int depth) {
        if(root == NULL) {
            return -1;
        }

        int l = getD(root -> left, ans, depth + 1) + 1;
        int r = getD(root -> right, ans , depth + 1) + 1;

        ans = max(ans, l+r);
        return max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        getD(root, ans, 0);
        return ans;
    }
};
