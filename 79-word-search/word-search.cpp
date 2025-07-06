class Solution {
public:
    bool f(vector<vector<char>>& board, string word, vector<vector<bool>> &vis, int row, int col, int i) {
        if (i == word.size()) {
            return true;
        }

        int n = board.size();
        int m = board[0].size();

        int delrow[4] = {-1, 0, 1, 0};  
        int delcol[4] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == word[i]) {
                vis[nrow][ncol] = true;
                if (f(board, word, vis, nrow, ncol, i + 1)) {
                    return true;
                }
                vis[nrow][ncol] = false;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();  
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = true;
                    if (f(board, word, vis, i, j, 1)) {
                        return true;
                    }
                    vis[i][j] = false;
                }
            }
        }

        return false;
    }
};
