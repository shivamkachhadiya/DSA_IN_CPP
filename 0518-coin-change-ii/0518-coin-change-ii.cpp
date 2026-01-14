class Solution {
public:
    // int solve(int target,vector<int>&arr,int i,vector<vector<int>>&dp){
    //     if (i == 0) {
    //         return (target % arr[0] == 0);
    //     }

    //     if(dp[i][target]!=-1)return dp[i][target];

    //     int take=0;
    //     if(arr[i]<=target){
    //         take=solve(target-arr[i],arr,i,dp);
    //     }
    //     int notake=0+solve(target,arr,i-1,dp);
    //     return dp[i][target]=take+notake;
    // }
    int solve(int target, vector<int>& arr, vector<vector<int>>& dp) {
    int n = arr.size();

    // base case
    for (int tar = 0; tar <= target; tar++) {
        if (tar % arr[0] == 0)
            dp[0][tar] = 1;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int tar = 0; tar <= target; tar++) {
            int notake = dp[ind - 1][tar];
            int take = 0;
            if (arr[ind] <= tar)
                take = dp[ind][tar - arr[ind]];

            dp[ind][tar] = take + notake;
        }
    }

    return dp[n - 1][target];
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    return solve(amount, coins, dp);
}
};
