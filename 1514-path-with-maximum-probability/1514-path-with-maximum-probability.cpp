class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb,
                          int start, int end) {
        // Build adjacency list
        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob}); // undirected graph
        }

        // Max-heap (probability, node)
        using State = pair<double,int>;
        priority_queue<State> pq;
        vector<double> dist(n, 0.0);

        dist[start] = 1.0;
        pq.push({1.0, start});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end) return prob; // early exit

            for (auto [nbr, edgeProb] : adj[node]) {
                double newProb = prob * edgeProb;
                if (newProb > dist[nbr]) {
                    dist[nbr] = newProb;
                    pq.push({newProb, nbr});
                }
            }
        }
        return 0.0; // unreachable
    }
};