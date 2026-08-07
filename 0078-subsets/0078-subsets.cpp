class Solution {
public:
vector<vector<int>>ans;
    void solve(vector<int>&nums,vector<int>&part,int i){
        if(i==nums.size()){
            ans.push_back(part);
            return;
        }
        if(i>nums.size()){
            return;
        }
        part.push_back(nums[i]);
        solve(nums,part,i+1);
        part.pop_back();
        solve(nums,part,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>part;
        solve(nums,part,0);
        return ans;
    }
};