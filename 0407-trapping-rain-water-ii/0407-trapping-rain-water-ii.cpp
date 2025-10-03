class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
     int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int,int>>, 
                       vector<pair<int, pair<int,int>>>, 
                       greater<>> pq;

        // Step 1: push all boundary cells into the heap
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = visited[m-1][j] = true;
        }

        int water = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};

        // Step 2: BFS with priority queue
        while (!pq.empty()) {
            auto [height, pos] = pq.top(); pq.pop();
            int x = pos.first, y = pos.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k];
                int ny = y + dirs[k+1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
                    continue;

                visited[nx][ny] = true;

                // If neighbor is lower, water can be trapped
                water += max(0, height - heightMap[nx][ny]);

                // Push updated neighbor into heap
                pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
            }
        }

        return water;
    }
};