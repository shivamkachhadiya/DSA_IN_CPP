#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>

class Solution {
public:
    long long myhours(std::vector<int>& arr, int hourly, int n) {
        long long totalh = 0; // changed from int to long long
        for (int i = 0; i < n; i++) {
            totalh += ceil((double)arr[i] / hourly);
        }
        return totalh;
    }

    int minEatingSpeed(std::vector<int>& arr, int h) {
        int n = arr.size();
        int max_value = *std::max_element(arr.begin(), arr.end());
        int low = 1, high = max_value, ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalhours = myhours(arr, mid, n); // mid passed as hourly rate
            if (totalhours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
