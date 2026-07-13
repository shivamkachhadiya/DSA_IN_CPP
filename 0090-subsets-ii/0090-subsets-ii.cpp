class Solution {
public:
    void solve(vector<int>&nums,int n,vector<vector<int>>&ans,vector<int>&part,int i){
        if(i>=n){
            ans.push_back(part);
            return;
        }
        part.push_back(nums[i]);
        solve(nums,n,ans,part,i+1);
        part.pop_back();
        int new_idx=i+1;
        while(new_idx<n&&nums[new_idx]==nums[new_idx-1]){
            new_idx++;
        }
        solve(nums,n,ans,part,new_idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>part;
        sort(nums.begin(), nums.end());
        solve(nums,n,ans,part,0);
        return ans;
    }
};