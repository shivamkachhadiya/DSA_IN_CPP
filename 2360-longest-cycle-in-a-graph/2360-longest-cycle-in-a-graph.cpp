class Solution {
public:
    int result=-1;

    void dfs(vector<int>&edges,int n,vector<bool>&vis,vector<int>&count,vector<int>&inRecursion,int startNode){
        vis[startNode]=true;
        inRecursion[startNode]=true;

        if(startNode!=-1 && edges[startNode]!=-1){
            if(vis[edges[startNode]]==false){
                count[edges[startNode]]=count[startNode]+1;
                dfs(edges,n,vis,count,inRecursion,edges[startNode]);
            }else if(inRecursion[edges[startNode]]){
                result=max(result,count[startNode]-count[edges[startNode]]+1);
            }
        }
        inRecursion[startNode]=false;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();

        vector<bool>vis(n,false);

        vector<int>count(n,1);

        vector<int>inRecursion(n,false);

        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(edges,n,vis,count,inRecursion,i);
            }
        }

        return result;
    }
};