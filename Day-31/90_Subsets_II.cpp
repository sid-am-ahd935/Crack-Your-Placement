class Solution {
public:
void subset(int sum, vector<int> &v, vector<int>&nums, vector<vector<int>>&ans, int n){
    ans.push_back(v);
    for(int i= sum; i<n; ++i){
        if(i>sum && nums[i]==nums[i-1]){
            continue;
        }
        v.push_back(nums[i]);
        subset(i+1,v, nums, ans, n);
        v.pop_back();
        
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n= nums.size(); 
        vector<int>v;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        subset(0, v, nums, ans, n);
        return ans;
    }
};
