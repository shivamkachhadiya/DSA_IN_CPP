class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int h) {
        int n = arr.size();
        int left = 1;
        int right = 0;

        // Find maximum pile size
        for (int pile : arr) {
            right = max(right, pile);
        }

        int result = right;

        while (left <= right) {
            int k = (left + right) / 2;
            long long taketime = 0;
            for (auto x : arr) {
                taketime += (x + k - 1) / k; // ceiling without float
            }
            if (taketime <= h) {
                result = k;
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        return result;
    }
};