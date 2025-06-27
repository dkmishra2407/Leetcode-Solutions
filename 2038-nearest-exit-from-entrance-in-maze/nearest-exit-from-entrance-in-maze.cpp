class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(maze[i][j] == '+'){
                    vis[i][j] = 1;
                }
            }
        }

        vis[ent[0]][ent[1]] = 1;
        //row,col,cnt
        queue<pair<int,pair<int,int>>>q;

        q.push({ent[0],{ent[1],0}});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second.first;
            int cnt = q.front().second.second;
            q.pop();

            if((row == 0 || col == 0 || row == n-1 || col == m-1) && (row != ent[0] || col != ent[1])){
                return cnt;
            }

            int delrow[4] = {1,0,-1,0};
            int delcol[4] = {0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && maze[nrow][ncol] != '+' && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,{ncol,cnt+1}});
                }
            }
        }

        return -1;
    }
};