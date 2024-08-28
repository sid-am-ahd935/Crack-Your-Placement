class Solution {
private:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(vector<int> adj[], int V, int startVertex, vector<int>& ans) {
        vector<bool> visited(V, false);
        stack<int> s; 
        
       
        s.push(startVertex);
        
        while (!s.empty()) {
       
            int v = s.top();
            s.pop();
            
    
            if (!visited[v]) {
                // Mark it as visited
                visited[v] = true;
                ans.push_back(v);
                
              
                for(int j=adj[v].size()-1;j>=0;j--){
                    if(!visited[adj[v][j]]){
                        s.push(adj[v][j]);
                    }
                }
            }
        }
    } 
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        DFS(adj,V,0,ans);
        return ans;
    }
};
