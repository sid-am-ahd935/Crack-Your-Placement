class Solution {
private:
    // DFS function to traverse the tree
    void dfs(vector<vector<int>>& adj, int headID, vector<int>& informTime, int time, int& maxTime) {
        // Update the maximum time taken to inform any employee
        maxTime = max(time, maxTime);

        // Traverse through all the subordinates of the current employee
        for(int& nextEmp: adj[headID]) {
            // Recursive DFS call with updated time
            dfs(adj, nextEmp, informTime, time + informTime[headID], maxTime);
        }
    }

    // BFS function to traverse the tree level by level
    void bfs(vector<vector<int>>& adj, int headID, vector<int>& informTime, int& maxTime) {
        queue<pair<int,int>> q;
        q.push({headID, 0});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int v = temp.first;
            int time = temp.second;

            maxTime = max(time, maxTime);
            for(int &emp: adj[v]) {
                q.push({emp, time + informTime[v]});
            }
        }
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n); // Adjacency list to represent the company hierarchy

        for (int i = 0; i < manager.size(); i++) {
            int employee = i;
            int manager_e =  manager[i];

            if(manager_e != -1)
                adj[manager_e].push_back(employee);
        }

        int maxTime = 0;
        dfs(adj, headID, informTime, 0, maxTime);  
        // bfs(adj, headID, informTime, maxTime);  // You can also use BFS here instead of DFS
        return maxTime;  
    }
};
