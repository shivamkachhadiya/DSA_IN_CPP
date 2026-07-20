class Solution {
public:
    int result=-1;
    void solve(vector<int>&edges,int n,vector<bool>&vis,vector<int>&count,vector<bool>&inRecPath,int i){
        vis[i]=true;
        inRecPath[i]=true;

        if(edges[i]!=-1){
            if(vis[edges[i]]==false){
                //not visited
                count[edges[i]]=count[i]+1;
                solve(edges,n,vis,count,inRecPath,edges[i]);
            }else if(inRecPath[edges[i]]==true){
                //cycle mil gayi
                int temp=count[i]-count[edges[i]]+1;
                result=max(result,temp);
            }
        }
        inRecPath[i]=false;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool>vis(n,false);
        vector<int>count(n,1);
        vector<bool>inRecPath(n,false);

        for(int i=0;i<n;i++){
            if(edges[i]==-1)continue;
            if(vis[i]==false)
                solve(edges,n,vis,count,inRecPath,i);
        }
        return result;
    }
    
};