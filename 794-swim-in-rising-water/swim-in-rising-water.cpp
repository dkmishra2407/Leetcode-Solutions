#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    bool is_safe(int row, int col, int n) {
        return (row >= 0 && row < n && col >= 0 && col < n);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == n - 1) {
                return wt;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (is_safe(nrow, ncol, n)) {
                    int new_time = max(wt, grid[nrow][ncol]);
                    if (new_time < dist[nrow][ncol]) {
                        dist[nrow][ncol] = new_time;
                        pq.push({new_time, {nrow, ncol}});
                    }
                }
            }
        }

        return -1; 
    }
};
