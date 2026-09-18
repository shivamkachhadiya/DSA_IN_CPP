class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int nodeDistance=times[i][2];
            adj[u].push_back({v,nodeDistance});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //distance node
        pq.push({0,k});

        vector<int>dist_vec(n+1,1e9);
        dist_vec[k]=0;
        while(!pq.empty()){
            int dist=pq.top().first;
            int Node=pq.top().second;
            pq.pop();
             if(dist > dist_vec[Node]) continue; 
            for(auto &x:adj[Node]){
                int nextNodeDistance=x.second;
                int nextNode=x.first;
                if(dist_vec[nextNode]>nextNodeDistance+dist){
                    dist_vec[nextNode]=nextNodeDistance+dist;
                    pq.push({nextNodeDistance+dist,nextNode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){  
            if(dist_vec[i]==1e9) return -1;
            ans=max(ans,dist_vec[i]);
        }
        return ans;
    }
};