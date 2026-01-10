class Solution {
public:
    bool solvekahnsBFS(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        vector<int> indegree(V);
        // indegree vector
        for (auto i : adj) {
            for (auto j : i.second) {
                indegree[j]++;
            }
        }

        // push initially
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto i : adj[front]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        if(ans.size()==V)return true;
        else return false;
    }
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        return solvekahnsBFS(V, prerequisites);
    }
};