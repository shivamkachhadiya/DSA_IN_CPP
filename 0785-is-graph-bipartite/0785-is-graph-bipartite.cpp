class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> colour(n, -1);

        for(int start = 0; start < n; start++) {
            if(colour[start] == -1) {
                queue<int> q;
                q.push(start);
                colour[start] = 0;

                while(!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for(auto &v : adj[u]) {
                        if(colour[v] == -1) {
                            colour[v] = !colour[u];
                            q.push(v);
                        } else if(colour[v] == colour[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
