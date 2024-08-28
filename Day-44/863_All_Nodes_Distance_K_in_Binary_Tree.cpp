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
public:
    void parentLevelOrder(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL)
            return;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) {
                    q.push(t->left);
                    mp[t->left] = t;
                }
                if (t->right) {
                    q.push(t->right);
                    mp[t->right] = t;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        
        parentLevelOrder(root, mp);
        for(auto i:mp)
        {
            cout<<i.first->val <<" "<<i.second->val;
        }
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<TreeNode*, bool> mp1;
        queue<TreeNode*> q;
        q.push(target);
        
        int level = 0;
        mp1[target]=1;
        while (!q.empty()) {
            if(level++==k)break;
            int n = q.size();
            while (n--) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left && !mp1[t->left]) {
                    q.push(t->left);
                    mp1[t->left] = 1;
                }
                if (t->right && !mp1[t->right]) {
                    q.push(t->right);
                    mp1[t->right] = 1;
                }
                if (mp[t] && !mp1[mp[t]]) {
                    q.push(mp[t]);
                    mp1[mp[t]] = 1;
                }
                
            }
            
        }
        while (!q.empty()) {
            TreeNode* p= q.front();
            q.pop();
            ans.push_back(p->val);
        }
        return ans;
    }
};
