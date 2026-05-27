class Solution {
public:
    void solve(vector<int>&arr,int n,vector<bool>&vis,vector<int>&part,vector<vector<int>>&ans){
        if(part.size()==n){
            ans.push_back(part);
            return;
        }
        for(int i=0;i<n;i++){
            
            if(vis[i]==true)continue;
            //include
            part.push_back(arr[i]);
            vis[i]=true;

            //recursive call
            solve(arr,n,vis,part,ans);

            //backtrack
            part.pop_back();
            vis[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& arr) {
        int n=arr.size();
        vector<bool>vis(n,false);
        vector<vector<int>>ans;
        vector<int>part;
        solve(arr,n,vis,part,ans);
        return ans;

    }
};