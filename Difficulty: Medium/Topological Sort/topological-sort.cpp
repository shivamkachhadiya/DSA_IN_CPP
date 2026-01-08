class Solution {
  public:
  void dfs(int i,vector<bool>&visited,unordered_map<int,list<int>>&adj,
            stack<int>&st){
                
        visited[i]=1;
            for(auto index:adj[i]){
                if (!visited[index]){
                    dfs(index, visited, adj, st);
                }
            }
            
        st.push(i);
      
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<bool>visited(V,0);
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
        }
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<V;i++){
            if (!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        
        while(!st.empty()){
            int val=st.top();
            ans.push_back(val);
            st.pop();
        }
        return ans;
       
    }
};