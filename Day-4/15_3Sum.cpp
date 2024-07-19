class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Accepted max time complexity O(N^2*logN) which is this, should have also tried O(N^2) using fixed i and j&k moving pointer for finding 2Sum
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int i=0, k = nums.size()-1;

        while(i < k) {
            while(i < k) {
                int target = -(nums[i] + nums[k]);
                if(binary_search(nums.begin()+i+1, nums.begin()+k-1+1, target)) {
                    res.push_back({nums[i], target, nums[k]});
                }

                while(i < k && nums[k] == nums[k-1]) k--;
                k--;
            }

            k = nums.size()-1;
            while(i < k && nums[i] == nums[i+1]) i++;
            i++;
        }

        return res;
    }
};
