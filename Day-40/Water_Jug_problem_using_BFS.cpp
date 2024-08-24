class Solution{
	public:
	int util(int a,int b,int m,int n,int d,vector<vector<int>> &dp,vector<vector<int>> &vis){
	   // if((a==d&&b==0)||(a==0&&b==d)) return 0;
	   if(a==d||b==d) return 0;
	    if(dp[a][b]!=-1) return dp[a][b];
	    if(vis[a][b]==1) return INT_MAX;
	    vis[a][b]=1;
	    int res=INT_MAX;
	    //empty jug a and b
	    res=min(res,util(0,b,m,n,d,dp,vis));
	    res=min(res,util(a,0,m,n,d,dp,vis));
	    //fill jug a and b only if they are empty
	    if(a==0){
	        res=min(res,util(m,b,m,n,d,dp,vis));
	    }
	    if(b==0){
	        res=min(res,util(a,n,m,n,d,dp,vis));
	    }
	    //fill a from b or b from a 
	    res=min(res,util(a-min(a,n-b),b+min(a,n-b),m,n,d,dp,vis));
	    res=min(res,util(a+min(b,m-a),b-min(b,m-a),m,n,d,dp,vis));
	    return dp[a][b]=(res==INT_MAX?INT_MAX:res+1);
	}
	int minSteps(int m, int n, int d)
	{
	    // Code here
	    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	    vector<vector<int>> vis(m+1,vector<int>(n+1,0));
	    int res=util(0,0,m,n,d,dp,vis);
	    if(res==INT_MAX) return -1;
	    else return res;
	}
};
