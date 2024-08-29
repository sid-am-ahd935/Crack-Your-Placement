class Solution {
public:
    int tabuFindMax(vector<pair<int,int>>&strs,int m, int n) {
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));

        for(int i = strs.size()-1;i>=0;i--) {
            for( int j=0;j<=m;j++) {
                for(int k=0;k<=n;k++) {
                    int zeroes = strs[i].first;
                    int ones = strs[i].second;
                    int include=0,exclude=0;

                    if(j-zeroes >=0 && k-ones>=0) {
                        include = 1 + dp[i+1][j-zeroes][k-ones];
                    }
                    exclude = dp[i+1][j][k];
         
                    dp[i][j][k] = max(include,exclude);
                }
            }
        }

        return dp[0][m][n];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>>str1; // to store the pairs of {zeros,ones} of every string present in the strs vector
        for(auto s:strs) {
            int ones=0,zeros=0;
            for(auto ch:s) {
                if(ch=='1')ones++;
                if(ch=='0')zeros++;
            }
            str1.push_back({zeros,ones});
            // cout<<zeros<<" "<<ones<<endl;
        }

        vector<vector<vector<int>>>dp(str1.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return tabuFindMax(str1,m,n);
    }
};
