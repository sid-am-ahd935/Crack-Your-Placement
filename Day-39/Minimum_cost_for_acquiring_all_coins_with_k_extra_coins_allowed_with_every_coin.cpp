class Solution{
private:
    int solve(vector<int>&nums,int n , int amount,vector<vector<int>>&dp) {
        if(amount == 0)
            return 0;
        if(amount < 0 || n < 0)
            return INT_MAX-10000;
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        
        return dp[n][amount] = min(  (1 + solve(nums,n,amount-nums[n],dp)) , solve(nums, n-1, amount,dp) );
    }
public:
    int MinCoin(vector<int>nums, int amount) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(nums,n-1,amount,dp);
        if(ans == INT_MAX-10000)return -1;
       return ans;
    }
};
