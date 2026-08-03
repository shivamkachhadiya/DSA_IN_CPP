class Solution {
public:
    int countPaths(int n, vector<vector<int>>& arr) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < arr.size(); i++) {
            int source = arr[i][0];
            int destination = arr[i][1];
            int time = arr[i][2];
            adj[source].push_back({destination, time});
            adj[destination].push_back({source, time});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, 0});
        vector<long long> dist_vec(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist_vec[0] = 0;
        ways[0] = 1;
        int MOD = (int)1e9 + 7;
        while (!pq.empty()) {
            int node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();
            if (dist > dist_vec[node])
                continue;
            for (auto& x : adj[node]) {
                int newNode = x.first;
                long long newDist = dist + x.second;

                if (newDist < dist_vec[newNode]) {
                    dist_vec[newNode] = newDist;
                    pq.push({newDist, newNode});
                    ways[newNode] = ways[node];
                } else if (newDist == dist_vec[newNode]) {
                    ways[newNode] = (ways[newNode] + ways[node]) % MOD;
                }
            }
        }
        return (ways[n - 1]) % MOD;
    }
};