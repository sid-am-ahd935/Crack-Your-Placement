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
    TreeNode* convert(int left, int right, vector<int> nums) {
        // Base Case
        if(left > right)
            return NULL;
        
        int mid = left + (right - left)/2;
        
        return new TreeNode(
            nums[mid],
            convert(left, mid - 1, nums),
            convert(mid + 1, right, nums)
        );
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(0, nums.size() - 1, nums);
    }
};
