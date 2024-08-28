class Solution {
public:
	bool dfsCycle(unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited,
    unordered_map<int,bool>&dfsVisited,int node){
        visited[node]=true;
        dfsVisited[node]=true;
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                bool isCycle=dfsCycle(adj,visited,dfsVisited,neighbor);
                if(isCycle){
                    return true;
                }
            }
            else if(dfsVisited[neighbor]){
                return true;
            }
        }
        dfsVisited[node]=false;
        return false;
    }
    bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        unordered_map<int,list<int>>adj;
        for(int i=0;i<P;i++){
            int u=prerequisites[i].first;
            int v=prerequisites[i].second;
            adj[u].push_back(v);
        }
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                bool isCycle=dfsCycle(adj,visited,dfsVisited,i);
                if(isCycle){
                    return false;
                }
            }
        }
        return true;
    }
};
