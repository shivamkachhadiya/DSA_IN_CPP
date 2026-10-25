class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0;
        int maxAns = 0;
        int currLen = 0;
        for (int right = 0; right < n; right++) {
            if (arr[right] == 0) {
                k--;
            }
            while (k < 0) {
                if (arr[left] == 0)
                    k++;
                left++;
            }

            maxAns = max(maxAns, right - left + 1);
        }

        return maxAns;
    }
};