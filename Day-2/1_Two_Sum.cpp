class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Already done this, using the most time efficient solution
        
        unordered_map<int, int> pair;
        for(int i=0; i<nums.size(); i++) {
            if(pair.find(target-nums[i]) != pair.end()) {
                return {i, pair[target-nums[i]]};
            }
            pair[nums[i]] = i;
        }

        return {-1, -1};
    }
};
