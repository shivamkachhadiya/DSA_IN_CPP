class Solution {
public:
    int result = -1;
    void dfs(int n, vector<int>& edges, vector<bool>& vis, vector<int>& count,
             vector<bool>& isRecPath, int i) {
        vis[i] = true;
        isRecPath[i] = true;
        if (edges[i] != -1) {
            if (vis[edges[i]] == false) {
                count[edges[i]] = count[i] + 1;
                dfs(n, edges, vis, count, isRecPath, edges[i]);
            } else if (isRecPath[edges[i]] == true) {
                // cycle mil gayi
                int len = count[i] - count[edges[i]] + 1;
                result = max(result, len);
            }

           
        }
         isRecPath[i] = false;
    }
    int longestCycle(vector<int>& Edge) {
        int n = Edge.size();
        vector<bool> vis(n, false);
        vector<int> count(n, 1);
        vector<bool> isRecPath(n, false);
        for (int i = 0; i < n; i++) {
            if (Edge[i] == -1)
                continue;
            if (vis[i] == false) {
                dfs(n, Edge, vis, count, isRecPath, i);
            }
        }
        return result;
    }
};