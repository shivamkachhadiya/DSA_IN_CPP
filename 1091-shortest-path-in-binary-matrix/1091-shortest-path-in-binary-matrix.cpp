class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

      

        vector<vector<int>> dist_vec(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; // PQ stres [DISTANCE, [ROW,COL]]

        pq.push({1, {0, 0}});
        dist_vec[0][0] = 1;

        int delRow[] = {-1, -1, 1, 0, -1, 1, 1, 0};
        int delCol[] = {1, 0, 1, 1, -1, 0, -1, -1};
        if(grid[0][0]==1||grid[n-1][m-1]==1)return -1;
        while (!pq.empty()) {
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row==n-1&&col==m-1)return dist;

            for (int i = 0; i < 8; i++) {
                int delta_row = row + delRow[i];
                int delta_col = col + delCol[i];
                int delta_dist = 1 + dist;
               
                if (delta_row >= 0 && delta_col >= 0 && delta_row < n &&
                    delta_col < m &&grid[delta_row][delta_col]==0&&dist_vec[delta_row][delta_col] > delta_dist) {
                    dist_vec[delta_row][delta_col] = delta_dist;
                    pq.push({delta_dist, {delta_row, delta_col}});
                }
            }
        }
        return -1;
    }
};