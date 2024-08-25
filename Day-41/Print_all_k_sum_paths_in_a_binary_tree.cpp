/*
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    void solve(Node* root, int target_sum, int current_sum, unordered_map<int, int>& sum_freq, int &count) {
        if (root == nullptr) {
            return;
        }
        
        current_sum += root -> data;
        count += sum_freq[current_sum - target_sum];
        sum_freq[current_sum] = sum_freq[current_sum] + 1;
        
        solve(root -> left, target_sum, current_sum, sum_freq, count);
        solve(root -> right, target_sum, current_sum, sum_freq, count);
        
        sum_freq[current_sum] -= 1;
    }
    
  public:
    int sumK(Node *root, int k) {
        int curr_sum = 0;
        int count = 0;
        unordered_map<int, int> sum_freq;
        sum_freq[0] = 1;
        
        solve(root, k, curr_sum, sum_freq, count);
        
        return count;
    }
};
