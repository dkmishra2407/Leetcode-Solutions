// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<pair<int, int>>> adj(n);
//         for (auto& flight : flights) {
//             int u = flight[0], v = flight[1], wt = flight[2];
//             adj[u].push_back({v, wt});
//         }

//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
//         pq.push({0, src, 0}); 

//         while (!pq.empty()) {
//             auto [cost, node, stops] = pq.top();
//             pq.pop();

//             if (node == dst) return cost;
//             if (stops > k) continue;

//             for (auto& [nei, wt] : adj[node]) {
//                 pq.push({cost + wt, nei, stops + 1});
//             }
//         }

//         return -1;
//     }
// };


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &f : flights)
            adj[f[0]].push_back({f[1], f[2]});
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q; // {node, cost}
        q.push({src, 0});
        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            vector<int> temp(dist); // make a copy to update after this level
            
            for (int i = 0; i < sz; ++i) {
                auto [u, cost] = q.front();
                q.pop();
                for (auto [v, w] : adj[u]) {
                    if (cost + w < temp[v]) {
                        temp[v] = cost + w;
                        q.push({v, temp[v]});
                    }
                }
            }
            dist = temp; // update after this level
            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};