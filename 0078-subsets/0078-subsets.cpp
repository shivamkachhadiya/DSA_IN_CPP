class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>&arr,int n,vector<int>part,int i){
        if(i>=n){
            ans.push_back(part);
            return;
        }
        part.push_back(arr[i]);
        solve(arr,n,part,i+1);
        part.pop_back();
        solve(arr,n,part,i+1);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();
        vector<int> part;
        solve(arr, n, part, 0);
        return ans;
    }
};