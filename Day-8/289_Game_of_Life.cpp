class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                int living = 0;
                // printf("(%d, %d): ", i, j);             // ----------
                for(int k=max(i-1, 0); k<=min(i+1, (int)board.size()-1); k++) {
                    // cout << "k(" << k << ") ";       // ----------
                    for(int l=max(j-1, 0); l<=min(j+1, (int)board[k].size()-1); l++) {
                        if(k == i && l == j) continue;
                        living += (abs(board[k][l]) == 1);
                        // cout << board[k][l] << ", ";    // ----------
                    }
                }
                // cout << "[" << living << "]" << endl;   // ----------
                if((living < 2 || living > 3) && board[i][j] == 1) {
                    board[i][j] = -1;    // Was alive but dies in next
                } else if(living == 3 && board[i][j] == 0) {
                    board[i][j] = 2;     // Was dead but alive in next
                }
            }
        }

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] == -1) board[i][j] = 0;
                if(board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};
