class Solution {
public:
    using ll = long long;
    struct State {
        ll cost;
        int i, j, parity;
        bool operator<(const State& other) const {
            return cost > other.cost; // min-heap
        }
    };

    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<ll>>> dist(m, vector<vector<ll>>(n, vector<ll>(2, LLONG_MAX)));
        priority_queue<State> pq;

        // entrance cost at (0,0)
        dist[0][0][1] = 1; 
        pq.push({1, 0, 0, 1});

        auto entrance = [&](int i, int j) {
            return 1LL * (i+1) * (j+1);
        };

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [cost, i, j, parity] = pq.top();
            pq.pop();
            if (cost != dist[i][j][parity]) continue;

            if (i == m-1 && j == n-1) return cost;

            // wait
            ll newCost = cost + penalty[i][j];
            if (newCost < dist[i][j][1-parity]) {
                dist[i][j][1-parity] = newCost;
                pq.push({newCost, i, j, 1-parity});
            }

            // moves
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                bool validMove = (parity == 1 && (d[0]==1 || d[1]==1)) || 
                                 (parity == 0 && (d[0]==-1 || d[1]==-1));
                ll add = entrance(ni,nj);
                if (!validMove) add += penalty[i][j];
                ll nc = cost + add;
                if (nc < dist[ni][nj][1-parity]) {
                    dist[ni][nj][1-parity] = nc;
                    pq.push({nc, ni, nj, 1-parity});
                }
            }
        }
        return -1; // should never happen
    }
};
