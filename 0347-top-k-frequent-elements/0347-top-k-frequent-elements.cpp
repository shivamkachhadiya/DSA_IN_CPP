class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        
        int n=arr.size();
        unordered_map<int,int>map;
        for(auto &x:arr){
            map[x]++;
        }
        priority_queue<pair<int,int>>pq;
        //freq->val
        for(auto &x:map){
            pq.push({x.second,x.first});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};