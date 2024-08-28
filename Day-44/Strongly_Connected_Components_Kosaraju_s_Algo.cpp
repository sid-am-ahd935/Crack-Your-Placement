class Solution {
	void tp(int i,vector<vector<int>> &adj,stack<int> &s,vector<bool> &visited){
        visited[i]=true;
        for(auto z:adj[i]){
            if(!visited[z])
                tp(z,adj,s,visited);
        }
        s.push(i);
        return;
    }
    
    void fun(int i,vector<int> new_adj[],vector<bool> &vis){
        vis[i]=true;
        for(auto x:new_adj[i]){
            if(!vis[x])
                fun(x,new_adj,vis);
        }
        return;
    }
public:    
    int kosaraju(int V, vector<vector<int>> &adj) {
        stack<int> s;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i])
                tp(i,adj,s,visited);
            
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        // inverse adj
        vector<int> new_adj[V];
        for(int i=0;i<V;i++){
            for(auto z:adj[i]){
                new_adj[z].push_back(i);
            }   
        }
        // tp dfs
        int res=0;
        vector<bool> vis(V,false);
        
        for(int i=0;i<ans.size();i++){
            if(!vis[ans[i]]){
                res++;
                fun(ans[i],new_adj,vis);
            }
            
        }
        return res;
    }
};
