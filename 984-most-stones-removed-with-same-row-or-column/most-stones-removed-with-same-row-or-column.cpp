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
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& arr) {
        int ans = 0;
        int n = arr.size();
        int rowmax = 0;
        int colmax = 0;
        for(auto it:arr){
            rowmax = max(rowmax,it[0]);
            colmax = max(colmax,it[1]);
        }
        unordered_set<int>s;

        DisjointSet ds(rowmax + colmax + 1);
        for(auto it:arr){
            int u = it[0];
            int v = it[1] + rowmax+ 1;

            ds.unionByRank(u,v);
            s.insert(u);
            s.insert(v);
        }
        int cnt = 0;
        for(auto it:s){
            if(it == ds.findUPar(it)){
                cnt++;
            }
        }

        return n - cnt;
    }
};