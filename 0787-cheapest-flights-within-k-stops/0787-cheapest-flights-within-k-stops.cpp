class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst,
                          int k) {
        // int n=arr.size();
        // int m=arr[0].size();
        const int INF = 1e9;
        vector<vector<pair<int, int>>> adj(n);
        // adj
        for (int i = 0; i < arr.size(); i++) {
            int u = arr[i][0];
            int v = arr[i][1];
            int distance = arr[i][2];
            adj[u].push_back({v, distance});
        }
        queue<pair<int, pair<int, int>>> pq;

        // pq= {stops,node,distance}
        pq.push({0, {src, 0}});
        vector<int> distArr(n, INF);
        distArr[src] = 0;

        while (!pq.empty()) {
            auto it = pq.front();
            pq.pop();
            int Stops = it.first;
            int Node = it.second.first;
            int Distance = it.second.second;

            // if (Stops > k) continue;
            // if(Node==dst)return Distance;

            for (auto& x : adj[Node]) {
                int newNode = x.first;
                int newCost = Distance + x.second;
                int newStop = Stops + 1;
                if (newStop <= k + 1) {
                    if (newCost < distArr[newNode]) {
                        distArr[newNode] = newCost;
                        pq.push({newStop, {newNode, newCost}});
                    }
                }
            }
        }
        if (distArr[dst] != 1e9)
            return distArr[dst];
        return -1;
    }
};