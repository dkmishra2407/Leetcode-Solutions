class Solution {
public:
    vector<vector<string>> ans;

    bool is_safe(int row, int col, vector<int>& cols) {
        for (int k = 0; k < row; k++) {
            if (col == cols[k] || abs(row - k) == abs(col - cols[k])) {
                return false;
            }
        }
        return true;
    }

    void f(int row, vector<int>& cols, int n) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                board[i][cols[i]] = 'Q';
            }
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (is_safe(row, j, cols)) {
                cols.push_back(j);
                f(row + 1, cols, n);
                cols.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols;
        f(0, cols, n);
        return ans;
    }
};
