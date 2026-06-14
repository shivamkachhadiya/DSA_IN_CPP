class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto &p:freq){
            q.push({p.second, p.first});
        }
        vector<int>ans;
        while(k!=0){
            ans.push_back(q.top().second);
            q.pop();
            k--;
        }
        return ans;

    }
};