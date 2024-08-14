class NumArray {
private:
    vector<int> arr;
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        this -> arr = nums;
        prefix.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++) {
            prefix.push_back(nums[i] + prefix[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        int diff = 0;
        if(left > 0) diff = prefix[left-1];
        return prefix[right] - diff;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
