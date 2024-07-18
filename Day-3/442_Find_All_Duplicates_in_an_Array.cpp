class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // I think I have already done this
        // Will have to revisit this later for more fluency
        vector<int> res;

        for(int i=0; i<nums.size(); i++) {
            if(nums[abs(nums[i])-1] < 0) {
                res.push_back(abs(nums[i]));
            } else {
                nums[abs(nums[i])-1] = - nums[abs(nums[i])-1];    // Converting to negative at the index
            }
        }

        return res;
    }
};
