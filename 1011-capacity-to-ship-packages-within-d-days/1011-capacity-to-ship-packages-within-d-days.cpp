class Solution {
public:
    bool isValid(vector<int>& arr, int days, int n, int max_allow_cap) {
        int days_req = 1;
        int curr_cap = 0;
        for (int i = 0; i < n; i++) {
            curr_cap += arr[i];
            if (curr_cap > max_allow_cap) {
                days_req++;
                curr_cap = arr[i];
            }
        }
        return days_req <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = 0;
        for (auto& x : weights) {
            end += x;
        }
        int ans = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (isValid(weights, days, weights.size(), mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};