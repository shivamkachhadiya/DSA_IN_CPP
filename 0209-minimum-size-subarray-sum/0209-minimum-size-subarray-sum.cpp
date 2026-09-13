class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int left = 0;
        int sum = 0;
        int n = arr.size();
        int minAns = INT_MAX;
        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum >= target) {
                minAns = min(minAns, right - left + 1);

                sum -= arr[left];
                left++;
            }
        }
        return minAns==INT_MAX?0:minAns;
    }
};