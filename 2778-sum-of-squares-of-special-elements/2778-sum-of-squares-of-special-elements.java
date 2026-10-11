class Solution {
    public int sumOfSquares(int[] nums) {
        int ans=0,n=nums.length;
        for(int i=0;i<n;i++){
            ans+=(n%(i+1))==0?nums[i]*nums[i]:0;
        }
        return ans;
    }
}