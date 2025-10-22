class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&part,int i,int n){
        if(i>=n){
            ans.push_back(part);
            return;            
        }
        //include
        part.push_back(nums[i]);
        solve(nums,ans,part,i+1,n);

        //exclude
        part.pop_back();
        solve(nums,ans,part,i+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>part;
        int i=0;
        int n=nums.size();
        solve(nums,ans,part,i,n);
        return ans;
    }
};