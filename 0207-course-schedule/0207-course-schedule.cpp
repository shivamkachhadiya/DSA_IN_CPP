class Solution {
public:
    bool solve(int s, vector<bool>& vis, vector<bool>& rec_path,
               vector<vector<int>>& graph) {
        vis[s] = true;
        rec_path[s] = true;
        for (int x : graph[s]) {
            if (vis[x] == false) {
                vis[x] = true;
                if (solve(x, vis, rec_path, graph)) {
                    return true;
                }
            } else {
                if (rec_path[x] == true) {
                    return true;
                }
            }
        }
        rec_path[s] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        vector<bool> vis(n, false);
        vector<bool> rec_path(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                if (solve(i, vis, rec_path, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};