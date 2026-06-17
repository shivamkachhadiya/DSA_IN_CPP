class Solution {
public:
    int solve(vector<int>& weight, int cap) {
        int days = 1, load = 0;
        int n = weight.size();
        for (int i = 0; i < n; i++) {
            if (load + weight[i] > cap) {
                days++;
                load = weight[i];
            } else {
                load += weight[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int start = *max_element(weights.begin(), weights.end());
        int end = 0;
        for (auto i : weights) {
            end += i;
        }
        int result = end; // Track minimum valid capacity

        while (start <= end) {
            int mid = (start + end) / 2;
            if (solve(weights, mid) <= days) {
                result = mid;  // This capacity works, save it
                end = mid - 1; // Search left for smaller capacity
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};