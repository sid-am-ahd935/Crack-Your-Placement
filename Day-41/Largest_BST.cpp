class Result {
public:
    int size;
    int min, max;
    
    Result(int size, int min, int max) {
        this->size = size;
        this->min = min;
        this->max = max;
    }
};

class Solution {
private:
    Result solve(Node *root) {
        if (!root){
            return Result(0, INT_MAX, INT_MIN);
        }
        Result left = solve(root->left);
        Result right = solve(root->right);
        
        if (root->data > left.max && root->data < right.min) {
            return Result(
                1 + left.size + right.size,
                min(root->data, left.min),
                max(root->data, right.max)
            );
        }
        return Result(max(left.size, right.size), INT_MIN, INT_MAX);
    }
    
public:
    int largestBst(Node *root) {
        return solve(root).size;
    }
};
