class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<n;i++){
            int first=mat[i][0];
            int second=mat[i][1];
            int dist=(first*first)+(second*second);
            pq.push({dist,{first,second}});
        }
        vector<vector<int>>ans;
        while(k--){
            int x1=pq.top().second.first;
            int x2=pq.top().second.second;
            ans.push_back({x1,x2});
            pq.pop();

        }
        return ans;
    }
};