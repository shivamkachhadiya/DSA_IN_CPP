class Solution {
public:
    vector<int> solve(vector<int>& edges, int start, int n) {
        vector<int> dist_arr(n, -1);
        vector<bool> vis(n, false);

        int curr = start;
        int d = 0;

        while (curr != -1 && !vis[curr]) {
            vis[curr] = true;
            dist_arr[curr] = d;
            curr = edges[curr];
            d++;
        }

        return dist_arr;
    }

    int closestMeetingNode(vector<int>& edges, int c1, int c2) {
        int n = edges.size();
        vector<int> c1_dist_arr = solve(edges, c1, n);
        vector<int> c2_dist_arr = solve(edges, c2, n);

        int answer = -1;
        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            // Dono yahan pahunch sakte hone chahiye
            if (c1_dist_arr[i] == -1 || c2_dist_arr[i] == -1)
                continue;
            int curr = max(c1_dist_arr[i], c2_dist_arr[i]);

            if (curr < best) {
                best = curr;
                answer = i;
            }
        }

        return answer;
    }
};