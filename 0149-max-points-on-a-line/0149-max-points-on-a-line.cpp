class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int maxPoints = 1;
        for (int i = 0; i < n; ++i) {
            int duplicate = 1;
            unordered_map<string, int> slopeCount;
            for (int j = i + 1; j < n; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    duplicate++;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                string slope = to_string(dx) + "," + to_string(dy);
                slopeCount[slope]++;
            }
            int best = 0;
            for (auto& p : slopeCount) {
                best = max(best, p.second);
            }
            maxPoints = max(maxPoints, best + duplicate);
        }
        return maxPoints;
    }
    
    int gcd(int a, int b) {
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};