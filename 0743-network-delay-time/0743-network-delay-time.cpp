class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        int size = times.size();
        for (int i = 0; i < size; i++) {
            int source = times[i][0];
            int destination = times[i][1];
            int time = times[i][2];
            adj[source].push_back({destination, time});
        }
        vector<int> dist_vec(n+1, 1e9);
        dist_vec[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto& x : adj[node]) {
                int newNode = x.first;
                int newDist = dist + x.second;
               
                if (newDist < dist_vec[newNode]) {
                    dist_vec[newNode] = newDist;
                    pq.push({newDist, newNode});
                }
            }
        }
        int ans=*max_element(dist_vec.begin()+1,dist_vec.end());
        if(ans==1e9)return -1;
        return ans;
    }
};