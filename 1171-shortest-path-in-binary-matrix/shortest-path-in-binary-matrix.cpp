class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));  
        dist[0][0] = 1;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        // wt, row, col
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; 
        pq.push({1, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();  
            int wt = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            int delrow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};  
            int delcol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

            for (int i = 0; i < 8; i++) {  
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (is_safe(nrow, ncol, n,grid) && dist[nrow][ncol] > dist[row][col] + 1) { 
                    dist[nrow][ncol] = dist[row][col] + 1;
                    pq.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }

        if(dist[n-1][n-1] == INT_MAX){
            return -1;
        }
        return dist[n - 1][n - 1];
    }

    bool is_safe(int r, int c, int n,vector<vector<int>>& grid) {
        return (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0);  
    }
};
