class Solution {
public:
    bool solve(vector<int>&arr,int k,int mid){
        int count=1;
        int curr=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>mid)return false;
            else if(arr[i]+curr<=mid){
                curr=curr+arr[i];
            }else{
                count++;
                //curr=arr[mid]; 
                curr=arr[i];
            }
            if(count>k)return false;
        }
     return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int start=0;
        int ans=0;
        int end=0;
        int n=nums.size();
         for(int i=0;i<n;i++){
            end=end+nums[i];
        }
        while(start<=end){
            int mid=(start+end)/2;
            if(solve(nums,k,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};