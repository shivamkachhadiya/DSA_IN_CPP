//created 17/03/2026
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        vector<int> bucket(k, 0);
        return backtrack(nums, bucket, target, 0);
    }

    bool backtrack(vector<int>& nums, vector<int>& bucket, int target, int idx) {
        if (idx == nums.size()) {
            for (int b : bucket) if (b != target) return false;
            return true;
        }
        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] + nums[idx] > target) continue;
            bucket[i] += nums[idx];
            if (backtrack(nums, bucket, target, idx + 1)) return true;
            bucket[i] -= nums[idx];
            if (bucket[i] == 0) break;
        }
        return false;
    }
};
