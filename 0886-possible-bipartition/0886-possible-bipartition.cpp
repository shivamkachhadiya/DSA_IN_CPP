class Solution {
public:
    bool solve(vector<vector<int>>& adj, int start, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for(int &v:adj[u]){
                if(color[v]==color[u]){
                    return false;
                }
                if(color[v]==-1){
                    q.push(v);
                    color[v]=!color[u];
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < arr.size(); i++) {
            int u = arr[i][0];
            int v = arr[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (solve(adj, i, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};