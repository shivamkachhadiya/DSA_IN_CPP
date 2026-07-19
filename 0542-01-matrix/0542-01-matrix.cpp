class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp_grid = mat;
        queue<pair<pair<int, int>,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = true;
                    // temp_grid[i][j]=1;
                    q.push({{i,j},0});
                }
                }
            }
            int ans = -1;
            while (!q.empty()) {
                int i = q.front().first.first;
                int j = q.front().first.second;
                int time = q.front().second;
                q.pop();

                temp_grid[i][j] = time;

                int delR[] = {-1, +1, 0, 0};
                int delC[] = {0, 0, -1, +1};

                for (int k = 0; k < 4; k++) {
                    int delRow = delR[k] + i;
                    int delCol = delC[k] + j;

                    if (delRow >= 0 && delCol >= 0 && delRow < n &&
                        delCol < m) {
                        if (vis[delRow][delCol] == false) {
                            vis[delRow][delCol] = true;
                            q.push({{delRow,delCol},time+1});
                        }
                    }
                }
            }
            return temp_grid;
        }
    };