class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int source = flights[i][0];
            int dest = flights[i][1];
            int cost = flights[i][2];

            adj[source].push_back({dest, cost});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dest_arr(n, 1e9);
        dest_arr[src]=0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            for (auto x : adj[node]) {
                int newNode = x.first;
                int newCost = cost + x.second;
                int newStop = stop + 1;
                if (newStop <= k+1) {
                    if (newCost < dest_arr[newNode]) {
                        dest_arr[newNode] = newCost;
                        q.push({newStop, {newNode, newCost}});
                    }
                }
            }
        }
        if (dest_arr[dst] != 1e9)
            return dest_arr[dst];
        return -1;
    }
};