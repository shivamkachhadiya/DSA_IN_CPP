class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();

        int oldColor = image[sr][sc];
        if (oldColor == color)
            return image; // edge case

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == oldColor) {

                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }

        return image;
    }
};