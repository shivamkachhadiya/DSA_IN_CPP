class Solution {
public:
int i=0;
    int removeDuplicates(vector<int>& nums) {
         int j = 1;
    //int first = nums[0];
    for(j;j<nums.size();j++){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
    }
  

    return i+1;
        
    }
};