class Solution {
  public:
  void bfs(vector<vector<int>> &adj,unordered_map<int,bool>&vis,
            vector<int>&ans,int node){
                queue<int>q;
                q.push(node);
                vis[node]=1;
                while(!q.empty()){
                    int front=q.front();
                    q.pop();
                    ans.push_back(front);
                    for(auto i:adj[front]){
                        if(!vis[i]){
                            q.push(i);
                            vis[i]=1;
                        }
                    }
                }
            }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        unordered_map<int,bool>vis;
        queue<int>q;
        vector<int>ans;
        int vertex=adj.size();
        for(int i=0;i<vertex;i++){
            if(!vis[i]){
                bfs(adj,vis,ans,i);
            }
        }
        return ans;
    }
};