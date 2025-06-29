class Solution {
public:
    int fun(const vector<int>& arr, int cap, int n) {
        int day = 1;
        int load = 0;
        for (int i = 0; i < n; i++) {
            if (load + arr[i] > cap) {
                day++;
                load = arr[i];
            } else {
                load = load + arr[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            int requiredDays = fun(arr, mid, n);

            if (requiredDays <= days) {
                ans = mid;         // store possible answer
                high = mid - 1;    // try to minimize capacity
            } else {
                low = mid + 1;     // need more capacity
            }
        }
        return ans;
    }
};
