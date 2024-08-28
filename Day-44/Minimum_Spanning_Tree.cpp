class Solution
{
	int p[1001]; // parent array for DSU
	// Function that performs find in DSU and path compression
	int find(int x){
	    if(p[x] >= 0) // if its not the parent
	        return p[x] = find(p[x]); // compressing path after find
	    return x; // if parent return parent
	}
	
	// Function that performs union in DSU and return if no cycle
	bool union_(int a, int b){
	    int pa = find(a), pb = find(b);
	    if(pa == pb) return false; // cycle exists, parent equal
	    int ra = -p[pa], rb = -p[pb];
	    if(ra > rb) p[pb] = pa;
	    else if(ra < rb) p[pa] = pb;
	    else{
	        p[pa] = pb;
	        p[pb]--;
	    }
	    return true; // no cycle
	}
	
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // adj:
        // [0] : {{1,5}, {2,1}}
        // [1] : {{0, 5}, {2,3}}
        // [2] : {{0, 1}, {1,3}}
        int ans = 0;
        vector<pair<int, pair<int,int>>> adjL; // <wei, <vert u, vert v>>
        for(int i = 0; i < V; i++){
            p[i] = -1; // mark parent of every node to -1 in DSU
            for(auto e: adj[i])
                adjL.push_back({e[1], {i, e[0]}}); // populate it
        }
        sort(adjL.begin(),adjL.end()); // sorts on 1st ele, i.e. weight
        for(auto e : adjL)
            if(union_(e.second.first, e.second.second)) // u, v union in DSU
                ans += e.first; // if no cycle, add to the weight in MST
        return ans; 
    }
};
