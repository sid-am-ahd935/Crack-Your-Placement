class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix[0].size(), n = matrix.size();
        int size = m*n;
        int level = 0;
        vector<int> res;

        int i = level, j = level;
        while(size > 0) {
            // Level wise traversal, outer level to inner level
            for(; j<m-level && size > 0; j++) {
                res.push_back(matrix[i][j]);
                size--;
            }
            j--;
            i++;
            for(; i<n-level && size > 0; i++) {
                res.push_back(matrix[i][j]);
                size--;
            }
            i--;
            j--;
            for(; j>=level && size > 0; j--) {
                res.push_back(matrix[i][j]);
                size--;
            }
            j++;
            i--;
            for(; i> level && size > 0; i--) {
                res.push_back(matrix[i][j]);
                size--;
            }
            i++;
            j++;
            level++;
        }
        return res;
    }
};
