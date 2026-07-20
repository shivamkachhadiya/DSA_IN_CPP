class Solution {
public:
    bool isValid(vector<int>& arr, int days, int max_allowed_capacity) {
        int local_days = 1;
        int cap = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max_allowed_capacity)
                return false;
            cap += arr[i];
            if (cap > max_allowed_capacity) {
                local_days++;
                cap = arr[i];
            }
        }
        if (local_days <= days) {
            return true;
        } else {
            return false;
        }
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();
        int sum = 0;
        for (auto& x : arr) {
            sum += x;
        }
        int end = sum;
        int start = 1;
        int ans = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (isValid(arr, days, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};