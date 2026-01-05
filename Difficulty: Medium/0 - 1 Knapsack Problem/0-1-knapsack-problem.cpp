class Solution {
  public:
    // int solve(vector<int> &wt, vector<int> &val,int i,int cap){
    //     if(i==0){
    //         if(wt[0]<=cap){
    //             return val[0];
    //         }else{
    //             return 0;
    //         }
    //     }
        
    //     int include=0;
        
    //     if(wt[i]<=cap){
    //         include=val[i]+solve(wt,val,i-1,cap-wt[i]);
    //     }
        
    //     int exclude=0+solve(wt,val,i-1,cap);
        
    //     return max(include,exclude);
        
    // }
    
    int solveMem(vector<int> &wt, vector<int> &val,int i,int cap,vector<vector<int>>&dp){
        if(i==0){
            if(wt[0]<=cap){
                return val[0];
            }else{
                return 0;
            }
        }
        if(dp[i][cap]!=-1){
            return dp[i][cap];
        }
        
        int include=0;
        
        if(wt[i]<=cap){
            include=val[i]+solveMem(wt,val,i-1,cap-wt[i],dp);
        }
        
        int exclude=0+solveMem(wt,val,i-1,cap,dp);
        
        return dp[i][cap]= max(include,exclude);
        
    }
    
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        //return solve(wt,val,n-1,W);
        return solveMem(wt,val,n-1,W,dp);
    }
};