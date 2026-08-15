class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
                                if (source == target) return 0;
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < routes.size(); i++) {
            for (auto& stops : routes[i]) {
                adj[stops].push_back(i);
            }
        }
        queue<int> q;
        vector<bool> vis(routes.size(), false);

        for (auto x : adj[source]) {
            q.push(x);
            vis[x] = true;
        }

        int count = 1;
        while (!q.empty()) {
            int sz=q.size();
            while(sz--){
                int frontElement = q.front();
                q.pop();

                for (auto x : routes[frontElement]) {
                    if(x==target)return count;

                    for(auto nextBus:adj[x]){
                        if(vis[nextBus]==false){
                            vis[nextBus]=true;
                            q.push(nextBus);
                        }
                    }
                    
                }
            }
            count++;
        }
        return -1;
    }
};