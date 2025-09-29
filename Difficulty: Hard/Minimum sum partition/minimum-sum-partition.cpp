class Solution {

  public:
  int total_sum(vector<int>&arr,int n){
      int sum=0;
      for(auto i:arr){
          sum+=i;
      }
      return sum;
  }
  int solve(vector<int>&arr,int n,int target,int index){
      if(index<0)return 0;
      
      //take
      int take=0;
      if(arr[index]<=target){
          take=arr[index]+solve(arr,n,target-arr[index],index-1);
      }
      
      //notTake
      int notTake=0+solve(arr,n,target,index-1);
      
      return max(take,notTake);
  }
  
    int solveMEM(vector<int>&arr,int n,int target,int index,
                                    vector<vector<int>>&dp){
      if(index<0)return 0;
      if(dp[target][index]!=-1)return dp[target][index];
      //take
      int take=0;
      if(arr[index]<=target){
          take=arr[index]+solveMEM(arr,n,target-arr[index],index-1,dp);
      }
      
      //notTake
      int notTake=0+solveMEM(arr,n,target,index-1,dp);
      
      return dp[target][index]=max(take,notTake);
  }
  
  
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        
        //formula minDiff=totalSum−2∗S1
        
        //calculate total sum of array
        int totalsum=total_sum(arr,n);
        int target=totalsum/2;
        vector<vector<int>> dp(target+1, vector<int>(n, -1));
        //int ans=solve(arr,n,target,n-1);
        int ans=solveMEM(arr,n,target,n-1,dp);
        int minDiff=totalsum-2*ans;
        return minDiff;
    }
};
