class DisjointSet {
    public:
    vector<int> rank, size, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int up = findpar(u);
        int vp = findpar(v);

        if (up == vp)
            return;

        if (rank[up] > rank[vp]) {
            parent[vp] = up;
        } else if (rank[vp] > rank[up]) {
            parent[up] = vp;
        } else {
            parent[up] = vp;
            rank[vp]++;
        }
    }

    void unionBySize(int u, int v) {
        int up = findpar(u);
        int vp = findpar(v);

        if (up == vp)
            return;

        if (size[up] > size[vp]) {
            parent[vp] = up;
            size[up] += size[vp];
        } else {
            parent[up] = vp;
            size[vp] += size[up];
        }
    }

    int getSize(int node) { return size[findpar(node)]; }
};

class Solution {
public:
    bool is_safe(int row, int col, int n) {
        return (row >= 0 && row < n && col >= 0 && col < n);
    }

    void f(vector<vector<int>>& grid, int row, int col,
           vector<vector<int>>& vis, DisjointSet& ds) {
        int n = grid.size();
        int basenode = row * n + col;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int base = r * n + c;

            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (is_safe(nrow, ncol, n) && vis[nrow][ncol] == 0 &&
                    grid[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    int node = nrow * n + ncol;
                    ds.unionBySize(base, node);
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int n = grid.size();

        DisjointSet ds(n * n); // assuming DisjointSet is already defined
        vector<vector<int>> vis(n, vector<int>(n, 0));

        // MAKE THE COMPONENTS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    f(grid, i, j, vis, ds);
                }
            }
        }

        // store sizes of each component
        unordered_map<int, int> m;
        for (int i = 0; i < n * n; i++) {
            int p = ds.findpar(i);
            m[p] = ds.size[p]; // assuming size[] is public or accessible
        }

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        // GO THROUGH EACH NODE
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int ans = 1;
                    unordered_set<int> st;

                    for (int k = 0; k < 4; k++) {
                        int nrow = i + delrow[k];
                        int ncol = j + delcol[k];

                        if (is_safe(nrow, ncol, n) && grid[nrow][ncol]) {
                            int node = nrow * n + ncol;
                            int parent = ds.findpar(node);
                            if (st.find(parent) == st.end()) {
                                ans += m[parent];
                                st.insert(parent);
                            }
                        }
                    }
                    maxi = max(maxi, ans);
                }
            }
        }

        // in case the whole grid is already filled with 1s
        for (int i = 0; i < n * n; i++) {
            maxi = max(maxi, ds.size[ds.findpar(i)]);
        }

        return maxi;
    }
};