class Solution {
public:
    int ans = 0;

    bool is_safe(int row, int col, vector<int>& cols) {
        for (int i = 0; i < row; i++) {
            if (cols[i] == col || abs(i - row) == abs(cols[i] - col)) {
                return false;
            }
        }
        return true;
    }

    void f(int row, int n, vector<int>& cols) {
        if (row == n) {
            ans++;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (is_safe(row, j, cols)) {
                cols.push_back(j);
                f(row + 1, n, cols);
                cols.pop_back();
            }
        }
    }

    int totalNQueens(int n) {
        vector<int> cols;
        f(0, n, cols);
        return ans;
    }
};
