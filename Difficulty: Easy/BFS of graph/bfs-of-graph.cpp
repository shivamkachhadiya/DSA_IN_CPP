class Solution {
  public:
  void solveBFS(vector<vector<int>>&adj,unordered_map<int,bool>&visited,vector<int>&ans,int node){
      queue<int>q;
      q.push(node);
      visited[node]=1;
      while(!q.empty()){
          int frontnode=q.front();
          q.pop();
          ans.push_back(frontnode);
          for(auto i:adj[frontnode]){
              if(!visited[i]){
                  q.push(i);
                  visited[i]=1;
              }
          }
      }
  }
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int vertex=adj.size();
        vector<int>ans;
        unordered_map<int,bool>visited;
        
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                solveBFS(adj,visited,ans,i);
            }
        }
        return ans;
        
    }
};