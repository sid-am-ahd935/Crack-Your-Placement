class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL)  return true;

		if (Height(root) == -1)  return false;

		return true;
	}
    // Create a function to return the “height” of a current subtree using recursion...
	int Height(TreeNode *root) {
		if (root == NULL)  return 0;

		int leftHeight = Height(root -> left);
		int rightHight = Height(root -> right);

		if (leftHeight == -1 || rightHight == -1)  return -1;

        if (abs(leftHeight - rightHight) > 1)  return -1;

		return max(leftHeight, rightHight) + 1;
    }
};
