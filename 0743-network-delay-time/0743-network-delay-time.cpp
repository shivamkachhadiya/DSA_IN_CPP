class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using Edge = pair<int,int>; // (neighbor, weight)
        vector<vector<Edge>> adj(n+1);

        for (const auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }

        const int INF = INT_MAX;
        vector<int> dist(n+1, INF);
        dist[k] = 0;

        using State = pair<int,int>; // (distance, node)
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue; // skip stale entry

            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};