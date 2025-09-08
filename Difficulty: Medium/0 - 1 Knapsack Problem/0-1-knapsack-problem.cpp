class Solution {
  public:
  int solve(vector<int>&weight,vector<int>&value,int index,int capacity,vector<vector<int>>&dp){
      if(index==0){
          if(weight[0]<=capacity){
              return value[0];
          }else{
              return 0;
          }
      }
      if(dp[index][capacity]!=-1){
          return dp[index][capacity];
      }
      int include=0;
      if(weight[index]<=capacity){
          include=value[index]+solve(weight,value,index-1,capacity-weight[index],dp);
          
      }
      int exclude=0+solve(weight,value,index-1,capacity,dp);
      dp[index][capacity]=max(include,exclude);
      return dp[index][capacity];
  }
    int knapsack(int maxweight, vector<int> &val, vector<int> &weight) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(maxweight+1,-1));
        return solve(weight,val,n-1,maxweight,dp);
        
    }
};