class Solution {
public:
    bool isValid(vector<int>& arr, int n, int mid, double hour) {
        double take_hour = 0;
        for (int i = 0; i < n - 1; i++) {
            take_hour += ceil((double)arr[i] / mid);
        }
        take_hour += (double)arr[n - 1] / mid;
        return take_hour <= hour;
    }
    int minSpeedOnTime(vector<int>& arr, double hour) {
        int ans = -1;
        int start = 1;
        int end = 1e9;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (isValid(arr, arr.size(), mid, hour)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};