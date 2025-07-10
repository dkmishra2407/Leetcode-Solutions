class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        vector<vector<string>> ans;
        int n = arr.size();
        DisjointSet ds(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            int m = arr[i].size();

            for (int j = 1; j < m; j++) {
                auto it = mp.find(arr[i][j]);
                if (it != mp.end()) {
                    ds.unionByRank(i, it->second);
                }
                mp[arr[i][j]] = i;
            }
        }

        vector<vector<string>> adj(n + 1); 

        for (auto it : mp) {
            int node = it.second;
            adj[ds.findUPar(node)].push_back(it.first);
        }

        for (int i = 0; i < n; i++) { 
            if (!adj[i].empty()) {
                sort(adj[i].begin(), adj[i].end()); 
                vector<string> temp;
                temp.push_back(arr[i][0]);
                for (auto& email : adj[i]) {
                    temp.push_back(email);
                }
                ans.push_back(temp);
            }
        }

        return ans;
    }
};