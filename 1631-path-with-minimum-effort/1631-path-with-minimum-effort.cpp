class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        const int INF = INT_MAX;

        using State = pair<int, pair<int, int>>;
        priority_queue<State, vector<State>, greater<State>> pq;

        vector<vector<int>> dist(n, vector<int>(m, INF));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        auto inBounds =
            [&](int r, int c) { 
                return r >= 0 && c >= 0 && r < n && c < m;
        };

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1)
                return diff;

            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (!inBounds(newr, newc))
                    continue;

                int newEff = max(abs(mat[row][col] - mat[newr][newc]), diff);
                if (newEff < dist[newr][newc]) {
                    dist[newr][newc] = newEff;
                    pq.push({newEff, {newr, newc}});
                }
            }
        }

        return 0;
    }
};