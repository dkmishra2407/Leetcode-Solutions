class Solution {
public:
    bool is_safe(int r, int c, int n,int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);  
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(is_safe(nrow,ncol,n,m) && dist[nrow][ncol] > max(diff,abs(heights[nrow][ncol] - heights[row][col]))){
                    dist[nrow][ncol] = max(dist[row][col],abs(heights[nrow][ncol] - heights[row][col]));
                    pq.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }
        }

        return 0;
    }
};