class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>> q;
        for (auto& it : freq) {
            q.push({it.first, it.second});
        }
        int ans = 0;
        while (k) {
            if (k >= q.top().second) {
                ans = q.top().first;
                k -= q.top().second;
                q.pop();
            }else{
                return q.top().first;
                break;
            }
        }
        return ans;
    }
};