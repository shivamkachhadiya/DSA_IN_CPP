class Solution {
public:
 int solve(int i,int buy,vector<int>&arr ,vector<vector<int>>&dp){
        if(i>=arr.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
                int profit=0;

        if(buy){
            profit=max((-arr[i]+solve(i+1,0,arr,dp)),(0+solve(i+1,1,arr,dp)));
        }else{
            profit=max((+arr[i]+solve(i+2,1,arr,dp)),(0+solve(i+1,0,arr,dp)));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};