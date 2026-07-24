class Solution {
public:
    bool isValid(vector<int>& arr, int n, int d, int capacity) {
        int last_sum = arr[0];
        int days = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > capacity)
                return false;
            last_sum += arr[i];
            if (last_sum > capacity) {
                days++;
                last_sum = arr[i];
            }
        }
        if (days <= d) {
            return true;
        } else {
            return false;
        }
    }
    int shipWithinDays(vector<int>& arr, int d) {
        int n = arr.size();
        
        int start = *max_element(arr.begin(),arr.end());
        int sum = 0;
        for (auto& x : arr) {
            sum += x;
        }
        int end = sum;
        int ans = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (isValid(arr, n, d, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};