class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, vector<vector<int>>& edges,
             int u, int v, vector<bool>& vis) {
        vis[u] = true;
        if (u == v)
            return true;
        for (auto& x : adj[u]) {
            if (vis[x] == false) {
                if (dfs(adj, edges, x, v, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            vector<bool> vis(edges.size() + 1, false);

            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() &&
                dfs(adj, edges, u, v, vis)) {
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};