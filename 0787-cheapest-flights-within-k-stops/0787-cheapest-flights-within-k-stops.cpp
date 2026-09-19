class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = INT_MAX;

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            int u = f[0], v = f[1], w = f[2];
            adj[u].push_back({v, w});
        }

        // Queue holds (stops, node, cost)
        queue<tuple<int,int,int>> q;
        q.push({0, src, 0});

        vector<int> dist(n, INF);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();

            // Explore neighbors
            for (auto [nbr, price] : adj[node]) {
                int newCost = cost + price;
                int newStops = stops + 1;

                if (newStops <= k + 1 && newCost < dist[nbr]) {
                    dist[nbr] = newCost;
                    q.push({newStops, nbr, newCost});
                }
            }
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};
