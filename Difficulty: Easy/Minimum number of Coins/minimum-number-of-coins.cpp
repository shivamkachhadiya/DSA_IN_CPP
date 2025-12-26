class Solution {
  public:
    int solve(vector<int>&arr,int n,int index,int tar,
        vector<vector<int>>&dp){
        if(index==0){
            if(tar%arr[index]==0)return tar/arr[index];
            else return 1e9;
        }
   if (dp[index][tar] != -1)
            return dp[index][tar];
            int take=1e9;
        if(arr[index]<=tar){
            take=1+solve(arr,n,index,tar-arr[index],dp);
        }
        int nottake=0+solve(arr,n,index-1,tar,dp);
        return dp[index][tar]=min(take,nottake);
    }
    int findMin(int tar) {
        // code here
        vector<int>arr={1,2,5,10};
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        int ans=solve(arr,n,n-1,tar,dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};