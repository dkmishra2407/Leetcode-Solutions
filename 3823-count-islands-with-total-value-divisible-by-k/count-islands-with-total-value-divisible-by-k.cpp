class Solution {
public:
    bool is_safe(int nrow,int ncol,int n,int m){
        return (nrow >= 0 && ncol >=0 && nrow < n && ncol < m);
    }
    int f(int row, int col, vector<vector<int>>& grid,
          vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        int delrow[4] = {0,-1,0,1};
        int delcol[4] = {1,0,-1,0};

        long long sum = 0;
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row, col});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            sum += grid[r][c];
            for (int i = 0; i<4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (is_safe(nrow, ncol, n, m) && vis[nrow][ncol] == 0 &&
                    grid[nrow][ncol] != 0) {
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && vis[i][j] == 0) {
                    int cal = f(i, j, grid, vis);
                    if(cal%k == 0){
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};