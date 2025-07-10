class Disjoint{
    vector<int>rank,parent;
    public:
        Disjoint(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);

            for(int i=1;i<=n;i++){
                parent[i] = i;
            }
        }

        int Findparent(int node){
            if(node == parent[node]){
                return node;
            }

            return parent[node] = Findparent(parent[node]);
        }

        void Union(int u,int v){
            int pu = Findparent(u);
            int pv = Findparent(v);

            if(pu == pv) return;

            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }
            else if(rank[pu] > rank[pv]){
                parent[pv] = pu;
            }
            else{
                parent[pv] = pu;
                rank[pv]++;
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& arr) {
        Disjoint ds(n);
        vector<int>vis(n,0);
        int extraedges = 0;
        int no_of_components = 0;
        for(auto it:arr){
            int u = it[0];
            int v = it[1];

            if(ds.Findparent(u) != ds.Findparent(v)){
                ds.Union(u,v);
            }
            else{
                extraedges++;
            }
        }

        for(int i=0;i<n;i++){
            if(i == ds.Findparent(i)){
                no_of_components++;
            }
        }
        
        if( extraedges >= no_of_components - 1){
            return (no_of_components - 1);
        }
        return -1;
    }
};