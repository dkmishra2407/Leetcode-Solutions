class Solution {
public:
    vector<vector<int>> ans;
    int timer = 1;

    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &time, vector<int> &low, int parent) {
        vis[node] = 1;
        time[node] = low[node] = timer++;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, adj, vis, time, low, node);
                low[node] = min(low[node], low[it]);

                if (low[it] > time[node]) {
                    ans.push_back({node, it});
                }
            } else {
                low[node] = min(low[node], time[it]); // ← corrected this line
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0), time(n, 0), low(n, 0);
        dfs(0, adj, vis, time, low, -1);

        return ans;
    }
};
