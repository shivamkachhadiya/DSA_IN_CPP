class Solution {
public:
    int smallestDivisor(vector<int>& arr, int th) {

        int n = arr.size();
        int ans = INT_MAX;
        int max = *max_element(arr.begin(), arr.end());
        int low = 1;
        int high = max;
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum =sum+ (int)ceil((double)arr[i] / mid);
            }
            if (sum <= th) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {

                low = mid + 1;
            }
        }
        return ans;
    }
};