class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;
        // Min‑heap of (freq, num); size at most k
        // This keeps the smallest freq on top, so we remove the least frequent
        using FreqNum = pair<int, int>; // (freq, num)
        priority_queue<FreqNum> pq;

        for (auto& p : freq)
            pq.push({p.second, p.first});

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};