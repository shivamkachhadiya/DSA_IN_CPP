class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = 0;
        int left=0;
        int zeros = 0;
        for (int right = 0; right < n; right++) {
            if (arr[right] == 0) {
                zeros++;
            }
            while (zeros > k) {
                if (arr[left] == 0) {
                    zeros--;
                }
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};