class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&part,int i){
        if(i==nums.size()){
            ans.push_back(part);
            return;
        }
        part.push_back(nums[i]);
        solve(nums,ans,part,i+1);
        part.pop_back();
        solve(nums,ans,part,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>part;
        solve(nums,ans,part,0);
        return ans;
    }
};
