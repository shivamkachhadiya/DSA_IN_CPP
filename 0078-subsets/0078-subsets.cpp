class Solution {
public:
    void solve(vector<int>&arr,int n,vector<int>&part,vector<vector<int>>&ans,int i){
        if(i>=n){
            ans.push_back(part);
            return;
        }
        part.push_back(arr[i]);
        solve(arr,n,part,ans,i+1);
        part.pop_back();
        solve(arr,n,part,ans,i+1);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        int n=arr.size();
        vector<int>part;
        vector<vector<int>>ans;
        solve(arr,n,part,ans,0);
        return ans;
    }
};