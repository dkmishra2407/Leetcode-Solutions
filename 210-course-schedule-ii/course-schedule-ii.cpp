
class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto itr : adj[i]) {
                indegree[itr]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return ans;
    }

    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int> adj[n + 1];
        int m = arr.size();

        for (int i = 0; i < m; i++) {
            adj[arr[i][0]].push_back(arr[i][1]);
        }

        vector<int> ans;
        ans = topoSort(n, adj);
        if(ans.size() != n){
            return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
