class Solution {
  public:
    int solve(vector<int>&weight,vector<int>&value,int index,int capacity){
        if(index==0){
            if(weight[0]<=capacity){
                return value[0];
            }else{
                return 0;
            }
        }
        
        //include
        int take=0;
        if(weight[index]<=capacity){
            take=value[index]+solve(weight,value,index-1,capacity-weight[index]);
        }
        
        
        //exclude
        int NotTake=0+solve(weight,value,index-1,capacity);
        
        return max(take,NotTake);
    }
    
    int solveMEM(vector<int>&weight,vector<int>&value,int index,int capacity,
                vector<vector<int>>&dp){
        if(index==0){
            if(weight[0]<=capacity){
                return value[0];
            }else{
                return 0;
            }
        }
        
        if(dp[index][capacity]!=-1)return dp[index][capacity];
        
        
        //include
        int take=0;
        if(weight[index]<=capacity){
            take=value[index]+solveMEM(weight,value,index-1,capacity-weight[index],dp);
        }
        
        
        //exclude
        int NotTake=0+solveMEM(weight,value,index-1,capacity,dp);
        
        return dp[index][capacity]=max(take,NotTake);
    }
    
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return solveMEM(wt,val,n-1,W,dp);
    }
};