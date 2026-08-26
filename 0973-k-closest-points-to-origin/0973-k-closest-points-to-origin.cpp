class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        for(int i=0;i<arr.size();i++){
            int x=arr[i][0];
            int y=arr[i][1];
            int diff=abs(x*x)+abs(y*y);
            pq.push({diff,{x,y}});
        }
        vector<vector<int>>ans;
        while(k--){
            int val1=pq.top().second.first;
            int val2=pq.top().second.second;
            ans.push_back({val1,val2});
            pq.pop();
        }
        return ans;
    }
};