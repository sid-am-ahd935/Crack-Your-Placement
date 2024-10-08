static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maxProfit(int k1, vector<int>& v) {
        vector<vector<int>> curr(k1+1,vector<int>(2,0));
        vector<vector<int>> prev(k1+1,vector<int>(2,0));
        int ans=0;
        for(int k=1;k<=k1;k++) prev[k][0]=-v[0];
        for(int i=1;i<v.size();i++)
        {
            for(int k=1;k<=k1;k++)
            {
                curr[k][0]=max(prev[k-1][1]-v[i],prev[k][0]);
            }
            for(int k=1;k<=k1;k++)
            {
                curr[k][1]=max(prev[k][0]+v[i],prev[k][1]);
                ans=max(ans,curr[k][1]);
            }
            prev=curr;
        }
        return ans;
        
    }
};
