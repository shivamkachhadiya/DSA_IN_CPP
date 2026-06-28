class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // adjacency list: {neighbor, flightCost}
        vector<pair<int, int>> graph[n];

        for (auto &flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];

            graph[from].push_back({to, cost});
        }

        // {currentCity, {totalCost, stopsUsed}}
        queue<pair<int, pair<int, int>>> q;

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        q.push({src, {0, -1}});

        while (!q.empty()) {

            auto [currentCity, state] = q.front();
            q.pop();

            auto [currentCost, stopsUsed] = state;

            for (auto &[nextCity, flightCost] : graph[currentCity]) {

                if (stopsUsed + 1 <= k &&
                    currentCost + flightCost < minCost[nextCity]) {

                    minCost[nextCity] = currentCost + flightCost;

                    q.push({nextCity,
                            {currentCost + flightCost, stopsUsed + 1}});
                }
            }
        }

        return (minCost[dst] == INT_MAX) ? -1 : minCost[dst];
    }
};