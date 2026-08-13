class Solution {
public:
    bool dfs(int u, int dst, vector<vector<pair<int,double>>>& adj,
             vector<bool>& vis, double prod, double &ans) {
        if (vis[u]) return false;
        vis[u] = true;

        if (u == dst) {
            ans = prod;
            return true;
        }

        for (auto &p : adj[u]) {
            int v = p.first;
            double val = p.second;
            if (dfs(v, dst, adj, vis, prod * val, ans)) return true;
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,int> mp;
        int idx = 0;

        // Assign indices to variables
        for (int i = 0; i < n; i++) {
            if (mp.find(equations[i][0]) == mp.end()) mp[equations[i][0]] = idx++;
            if (mp.find(equations[i][1]) == mp.end()) mp[equations[i][1]] = idx++;
        }

        // Build adjacency list
        vector<vector<pair<int,double>>> adj(idx);
        for (int i = 0; i < n; i++) {
            int u = mp[equations[i][0]];
            int v = mp[equations[i][1]];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0 / values[i]});
        }

        vector<double> results;
        for (auto &query : queries) {
            if (mp.find(query[0]) == mp.end() || mp.find(query[1]) == mp.end()) {
                results.push_back(-1.0);
                continue;
            }
            int src = mp[query[0]];
            int dst = mp[query[1]];
            double ans = -1.0;
            vector<bool> vis(n, false);

            dfs(src, dst, adj, vis, 1.0, ans);
            results.push_back(ans);
        }
        return results;
    }
};
