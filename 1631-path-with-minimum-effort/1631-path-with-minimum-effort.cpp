class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 1e9));
        vis[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};
        while (!pq.empty()) {
            int distance = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();            
            if (i == n-1 && j == m-1) return distance; 
            for (int k = 0; k < 4; k++) {
                int newRow = i + delRow[k];
                int newCol = j + delCol[k];
                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m) {
                    int jaha_se_aaye=mat[i][j];
                    int currNode = mat[newRow][newCol];

                    int diff = abs(currNode - jaha_se_aaye);
                    int newEffort=max(distance,diff);
                    if (newEffort < vis[newRow][newCol]) {
                        vis[newRow][newCol] = newEffort;
                        pq.push({newEffort,{ newRow, newCol}});
                    }
                }
            }
        }
        return vis[n-1][m-1];
    }
};