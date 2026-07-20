class Solution {
public:
    bool isValid(vector<int>& arr, int h, int k) {
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long c_val = ceil((double)arr[i] / k);
            sum += c_val;
        }
        if (sum <= h) {
            return true;
        } else {
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (isValid(piles, h, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};