#include<unordered_map>
#include<queue>
#include<list>
class Solution {
  public:
  void bfs(vector<vector<int>> &adj,
        unordered_map<int,bool>&visited,
            vector<int>&ans,int node){
                queue<int>q;
                q.push(node);
                visited[node]=1;
                while(!q.empty()){
                    int frontnode=q.front();
                    q.pop();
                    
                    //store front in ans
                    ans.push_back(frontnode);
                    
                    //traverse all neighbours of front node
                    for(auto i:adj[frontnode]){
                        if(!visited[i]){
                            q.push(i);
                            visited[i]=1;
                        }
                    }
                }
            }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int vertex=adj.size();
        unordered_map<int,bool>visited;
        vector<int>ans;
        for(int i=0;i<vertex;i++){
            if(!visited[i]){
                bfs(adj,visited,ans,i);
            }
        }
        return ans;
    }
};