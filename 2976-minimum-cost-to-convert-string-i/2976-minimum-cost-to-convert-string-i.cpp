class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        const long long INF = (long long)4e18;

        // dist[i][j] = minimum cost to convert char i -> char j
        long long dist[26][26];

        // init
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                dist[i][j] = (i == j ? 0 : INF);
            }
        }

        // direct edges from rules
        int m = original.size();
        for (int k = 0; k < m; ++k) {
            int u = original[k] - 'a';
            int v = changed[k] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[k]);
        }

        // Floyd–Warshall
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                if (dist[i][k] == INF)
                    continue;
                for (int j = 0; j < 26; ++j) {
                    if (dist[k][j] == INF)
                        continue;
                    long long through_k = dist[i][k] + dist[k][j];
                    if (through_k < dist[i][j]) {
                        dist[i][j] = through_k;
                    }
                }
            }
        }

        // compute total cost
        if (source.size() != target.size())
            return -1;
        long long ans = 0;

        for (int i = 0; i < (int)source.size(); ++i) {
            if (source[i] == target[i])
                continue;
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] == INF) {
                return -1; // impossible to convert this position
            }
            ans += dist[u][v];
        }

        return ans;
    }
};