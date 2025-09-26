class Solution {
  public:
    void solve(int i, unordered_map<int,bool>& visited,
               vector<vector<int>>& adj, vector<int>& ans) {
        ans.push_back(i);   // directly push here
        visited[i] = true;

        for (auto index : adj[i]) {
            if (!visited[index]) {
                solve(index, visited, adj, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        unordered_map<int,bool> visited;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                solve(i, visited, adj, ans);
            }
        }
        return ans;
    }
};
