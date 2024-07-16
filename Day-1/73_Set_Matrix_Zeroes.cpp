class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroes;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    zeroes.push_back({i, j});
                }
            }
        }

        for(auto& [i, j]: zeroes) {
            for(int k = 0; k<matrix[i].size(); k++) {
                matrix[i][k] = 0;
            }
            for(int k = 0; k<matrix.size(); k++) {
                matrix[k][j] = 0;
            }
        }

        return;
    }
};
