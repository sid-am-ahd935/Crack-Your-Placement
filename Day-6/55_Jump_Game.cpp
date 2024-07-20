class Solution {
public:
    bool canJump(vector<int>& nums) {
        // As long as jump=0 is out of reach, we can reach the end
        // Not needed
        // // if(nums[0] == 0) {
        // //     return nums.size() == 1;    // If first index is the last index
        // // }
        int max_jump = 0;
        for(int i=0; i<nums.size()-1; i++) {
            max_jump = max(max_jump-1, nums[i]);
            if(max_jump <= 0) {
                return false;
            }
        }
        return true;
    }
};
