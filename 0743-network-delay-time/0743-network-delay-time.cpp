class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> dist_arr(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push({0, k});
        dist_arr[k] = 0;
        while (!q.empty()) {
            int dist = q.top().first;
            int node = q.top().second;
            q.pop();
            for (auto& x : adj[node]) {
                int newNode = x.first;
                int newDist = dist + x.second;
                if (newDist < dist_arr[newNode]) {
                    dist_arr[newNode] = newDist;
                    q.push({newDist, newNode});
                }
            }
        }

        int ans = *max_element(dist_arr.begin() + 1, dist_arr.end());

        if (ans == 1e9)
            return -1;

        return ans;
    }
};