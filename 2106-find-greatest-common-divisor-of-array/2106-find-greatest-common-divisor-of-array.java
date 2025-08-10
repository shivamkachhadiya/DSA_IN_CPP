class Solution {
    int gcd(int a,int b){
        if(a==0){
            return b;
        }else{
            return gcd(b%a,a);
        }
    }
    public int findGCD(int[] nums) {
        int min=Integer.MAX_VALUE,max=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<min){
                min=nums[i];
            }

            if(nums[i]>max){
                max=nums[i];
            }
        }

        int result=gcd(min,max);
        return result;
    }
}