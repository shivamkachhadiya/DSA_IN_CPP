class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (const auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (order.size() != numCourses) {
            return {};
        }

        return order;
    }
};