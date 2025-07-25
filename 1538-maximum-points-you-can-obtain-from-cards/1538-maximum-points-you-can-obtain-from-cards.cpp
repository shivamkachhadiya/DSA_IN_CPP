class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int lsum = 0, rsum = 0;
        int maxsum = 0;
        
        // First, take all k elements from the left
        for(int i = 0; i < k; i++) {
            lsum += arr[i];
        }
        maxsum = lsum;

        // Now shift one by one from left to right
        int rightIndex = arr.size() - 1;
        for(int i = k - 1; i >= 0; i--) {
            lsum -= arr[i];              // remove from left
            rsum += arr[rightIndex--];   // add from right
            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};
