class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        if (mn == mx) return 0;
        
        int bucketSize = max(1, (mx - mn) / (n - 1)); // bucket ka size
        int bucketCount = (mx - mn) / bucketSize + 1;
        
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);
        
        for (int x : nums) {
            int idx = (x - mn) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], x);
            bucketMax[idx] = max(bucketMax[idx], x);
            used[idx] = true;
        }
        
        int prev = mn, ans = 0;
        for (int i = 0; i < bucketCount; i++) {
            if (!used[i]) continue;
            ans = max(ans, bucketMin[i] - prev); // gap calculate
            prev = bucketMax[i];
        }
        return ans;
    }
};
