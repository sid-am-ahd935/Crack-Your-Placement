class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // Either last 3, or first 2 and last [due to negative numbers]
        return max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
    }
};
