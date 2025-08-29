class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int temp=i%10;
            if(temp==nums[i])
            return i;
        }
        return -1;
        
    }
};