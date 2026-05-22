// class Solution {
// public:
//     vector<int>ans;
//     int size=0;
//     void solve(vector<int>&arr,int n,int i){
//         if(i>=n){
//             size=max(size,(int)ans.size());
//             return;
//         }

//         if(ans.empty()||ans.back()<arr[i]){
//             //include
//             ans.push_back(arr[i]);
//             solve(arr,n,i+1);
//             ans.pop_back();            
//         }
//         solve(arr,n,i+1);

//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         solve(nums,n,0);
//         return size;
//     }
// };
class Solution {
public:
    int solve(vector<int>& nums, int i, int prev,
              vector<vector<int>>& dp) {

        if (i == nums.size())
            return 0;

        // prev ranges from -1 to n-1
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // Include current element
        int take = 0;

        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(nums, i + 1, i, dp);
        }
        
        // Exclude current element
        int notTake = solve(nums, i + 1, prev, dp);

        return dp[i][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(nums, 0, -1, dp);
    }
};