class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        sums[0]++;
        int count = 0;
        int sum = 0;

        // Same approach as Subarray Sum Divisible by K
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(sums.find(sum-k) != sums.end()) {
                count += sums[sum-k];
            }
            sums[sum]++;
        }
        return count;
    }
};
