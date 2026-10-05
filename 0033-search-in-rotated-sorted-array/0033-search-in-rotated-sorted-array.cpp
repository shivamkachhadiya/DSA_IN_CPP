class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int n=nums.size();
        int end=n-1;

        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>=nums[start]){
                //start sorted
                if(nums[start]<=target&&target<nums[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                //right sorted
                if(nums[mid]<target&&target<=nums[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }

            }
        }
        return -1;   
    }
};