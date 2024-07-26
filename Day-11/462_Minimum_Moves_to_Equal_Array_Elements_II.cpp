class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int median = nums[nums.size()/2], ans = 0;      // not using median for even numbers, because that median will give decimal, not significant while whole numbers operations
        for(int n:nums) {
            ans += abs(median - n);
        }

        return ans;
    }
};
