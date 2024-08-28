class Solution {
private:
    void bfs(vector<int>& KnightPos, vector<int>& TargetPos, int N, int& ans, vector<vector<int>>& vis){
        int ix=KnightPos[0];
        int iy=KnightPos[1];
        int dirX[]={1,2,2,1,-1,-2,-2,-1};
        int dirY[]={2,1,-1,-2,-2,-1,1,2};
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{ix,iy}});
        while(!q.empty()){
            int lvl=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            vis[x][y]=1;
            for(int i=0;i<8;i++){
                int newx=x+dirX[i];
                int newy=y+dirY[i];
                if(newx==TargetPos[0] and newy==TargetPos[1]){
                    ans=lvl+1;
                    return;
                } else if(newx>=1 and newx<=N and newy>=1 and newy<=N and !vis[newx][newy]){
                        q.push({lvl+1,{newx,newy}});
                        vis[newx][newy]=1;
                }
                
            }
        }
        return;
    }
public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos,int N) {
        vector<vector<int>>vis(N+1,vector<int>(N+1));
        int ans=-1;
        bfs(KnightPos,TargetPos,N,ans,vis);
        return ans == -1 ? 0 : ans;
    }
};
