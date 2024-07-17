class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Already done it, will be doing this again for 45 days challenge
        // Two pointer approach
        int i=0, p=0;
        while(i+p < nums.size()) {
            if(nums[i+p] == 0) {
                p++;
            } else {
                swap(nums[i], nums[i+p]);
                i++;
            }
        }
    }
};
