#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    bool is_safe(int row, int col, int n, int m) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1; 
                }
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            bool rotHappened = false;
            for (int k = 0; k < size; k++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if (is_safe(nrow, ncol, n, m) && vis[nrow][ncol] == 0 &&
                        grid[nrow][ncol] == 1) {
                        fresh--;
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                        rotHappened = true;
                    }
                }
            }
            if (rotHappened) ans++;
        }

        if (fresh != 0) {
            return -1;
        }

        return ans;
    }
};
