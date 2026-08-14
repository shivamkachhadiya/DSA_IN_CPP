class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &x:map){
            pq.push({x.second,x.first});
        }
        for(int i=0;i<k;i++){
            int element=pq.top().second;
            ans.push_back(element);
            pq.pop();
        }
        return ans;
    }
};