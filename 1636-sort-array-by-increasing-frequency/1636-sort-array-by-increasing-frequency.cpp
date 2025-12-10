class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;

        auto cmp = [&](int a, int b) {
            if (freq[a] == freq[b])
                return a > b;
            return freq[a] < freq[b];
        };
        sort(nums.begin(), nums.end(), cmp);

        return nums;
    }
};
