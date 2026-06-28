class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n]; // node->to_node,dist
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q; //{top_node,{dist,stops}};
        vector<int> dist_v(n, INT_MAX);
        dist_v[src] = 0;
        q.push({src, {0, -1}});

        while (q.size() > 0) {
            auto [u, info] = q.front();
            q.pop();

            auto [u_dist, stops] = info;

            for (auto& [v, u_to_v_dist] : adj[u]) {
                if (u_dist + u_to_v_dist < dist_v[v] && stops + 1 <= k) {
                    dist_v[v] = u_dist + u_to_v_dist;
                    q.push({v, {u_dist + u_to_v_dist, stops + 1}});
                }
            }
        }
        if(dist_v[dst]==INT_MAX)return -1;else return dist_v[dst];
    }
};