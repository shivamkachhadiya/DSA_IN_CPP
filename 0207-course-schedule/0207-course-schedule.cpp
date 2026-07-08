class Solution {
public:
    bool bfs(int src, vector<bool>& vis, vector<bool>& recPath,
             vector<vector<int>>& edges) {
        vis[src] = true;
        recPath[src] = true;
        for (auto v : edges[src]) {
            if (!vis[v]) {
                if (bfs(v, vis, recPath, edges)) {
                    return true;
                }
            } else {
                if (recPath[v] == true) {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int course = edges[i][0];
            int pre = edges[i][1];

            adj[pre].push_back(course);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (bfs(i, vis, recPath, adj))
                    return false; // Cycle found
            }
        }

        return true;
    }
};