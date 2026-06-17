class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (auto& it : freq) {
            q.push({it.second, it.first});
        }
        vector<int> ans;
        while (k) {
            int val = q.top().second;
            q.pop();
            ans.push_back(val);
            k--;
        }
        return ans;
    }
};