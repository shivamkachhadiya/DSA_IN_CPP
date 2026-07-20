class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int desti = times[i][1];
            int time = times[i][2];

            adj[source].push_back({desti, time});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        vector<int> dest_arr(n + 1, 1e9);
        dest_arr[k] = 0;

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto& x : adj[node]) {
                int newNode = x.first;
                int newDist = x.second;
                int total_dist = dist + newDist;
                if (total_dist < dest_arr[newNode]) {
                    dest_arr[newNode] = total_dist;
                    pq.push({total_dist, newNode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dest_arr[i] == 1e9)
                return -1;
            ans = max(ans, dest_arr[i]);
        }
        return ans;
    }
};