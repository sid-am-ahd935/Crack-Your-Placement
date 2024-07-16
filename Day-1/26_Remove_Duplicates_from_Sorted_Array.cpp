class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = 1;
        int new_i = 0;
        int old = 0;
        while(old < nums.size()) {
            if(nums[old] == nums[new_i]) {
                old++;
            } else {
                new_i++;
                size++;
                nums[new_i] = nums[old];
            }
        }

        return size;
    }
};
