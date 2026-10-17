class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums,vector<int>&part,int n,int i){
        if(i>=n){
            ans.push_back(part);
            return;
        }

        part.push_back(nums[i]);
        solve(nums,part,n,i+1);
        part.pop_back();
        solve(nums,part,n,i+1);

        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>part;
        int n=nums.size();
        solve(nums,part,n,0);
        return ans;
    }
};