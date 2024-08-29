class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int f(vector<int>&arr,vector<vector<int>>&dp,int ind,int target){
        if(ind==0){
            if(target%arr[ind]==0){
                return target/arr[ind];
            }
            return INT_MIN;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int nottake=f(arr,dp,ind-1,target);
        int take=INT_MIN;
        if(target>=arr[ind]){
            take=1+f(arr,dp,ind,target-arr[ind]);
        }
        return dp[ind][target]=max(take,nottake);
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>arr;
        arr.push_back(x);arr.push_back(y);arr.push_back(z);
        sort(arr.begin(),arr.end());
        vector<vector<int>>dp(3,vector<int>(n+1,-1));
        f(arr,dp,2,n);
        int maxi=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<=n;j++ ){
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
        
    }
};
