class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        // Build the graph
        for (int i = 0; i < equations.size(); i++) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double value = values[i];
            graph[a][b] = value;
            graph[b][a] = 1.0 / value;
        }
        // Function to perform DFS
        function<double(const string&, const string&, unordered_set<string>&)> dfs = [&](const string& src, const string& target, unordered_set<string>& seen) -> double {
            if (graph.find(src) == graph.end() || graph.find(target) == graph.end()) {
                return -1.0;
            }
            if (src == target) {
                return 1.0;
            }
            seen.insert(src);
            for (const auto& neighbor : graph[src]) {
                if (seen.find(neighbor.first) != seen.end()) {
                    continue;
                }
                double result = dfs(neighbor.first, target, seen);
                if (result != -1.0) {
                    return result * neighbor.second;
                }
            }
            return -1.0;
        };
        // Process the queries
        vector<double> results;
        for (const auto& query : queries) {
            unordered_set<string> seen;
            results.push_back(dfs(query[0], query[1], seen));
        }
        return results;
    }
};
