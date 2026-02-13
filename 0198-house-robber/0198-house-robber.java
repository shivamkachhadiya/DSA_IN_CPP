class Solution {


    int solve(int i,int[]nums,int[]dp){
        if(i==0)return nums[i];
        if(i<0)return 0;

        if(dp[i]!=-1){
            return dp[i];
        }

        int pick=nums[i]+solve(i-2,nums,dp);
        int nonpick=0+solve(i-1,nums,dp);

        dp[i]=Math.max(pick,nonpick);

        return dp[i];
    }


    public int rob(int[] nums) {
        int []dp=new int[nums.length];
        Arrays.fill(dp,-1);

        int result=solve(nums.length-1,nums,dp);
        return result;

        
    }
}