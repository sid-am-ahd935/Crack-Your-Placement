// Little Optimisation Needed

class Solution {
private:
    bool check(int i, int j, vector<vector<char>>& board, string word, int p, vector<vector<bool>>& visited) {
        if(i >= board.size() || j >= board[0].size()) {
            return false;
        }
        if(board[i][j] != word[p]) {
            return false;
        }
        if(visited[i][j] == true) {
            return false;
        }

        if(p >= word.size() - 1) {
            return true;
        }
        bool flag = false;

        // cout << "Check Runs" << endl;

        if(i > 0) {
            // Up
            // cout << "UP Runs" << endl;
            visited[i][j] = true;
            flag = check(i-1, j, board, word, p+1, visited);
            visited[i][j] = false;
        }
        if(flag) return flag;

        if(i < board.size() - 1) {
            // Down
            // cout << "DOWN Runs" << endl;
            visited[i][j] = true;
            flag = check(i+1, j, board, word, p+1, visited);
            visited[i][j] = false;
        }
        if(flag) return flag;

        if(j > 0) {
            // Left
            // cout << "LEFT Runs" << endl;
            visited[i][j] = true;
            flag = check(i, j-1, board, word, p+1, visited);
            visited[i][j] = false;
        }
        if(flag) return flag;

        if(j < board[0].size() - 1) {
            // Right
            // cout << "RIGHT Runs" << endl;
            visited[i][j] = true;
            flag = check(i, j+1, board, word, p+1, visited);
            visited[i][j] = false;
        }
        if(flag) return flag;

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // First find out all starting points available
        vector<pair<int, int>> indexes;
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(word[0] == board[i][j]) {
                    indexes.push_back({i, j});
                }
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(auto& [i, j] : indexes) {
            if(check(i, j, board, word, 0, visited)) {
                return true;
            }
        }

        return false;
    }
};
