class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();  // Correct way to get the size of a vector


           for(int i=0;i<size;i++){
                if(target==nums[i]){
                    return i;
                }else if(target<nums[i]){
                    return i;
                }
            }



            return size;            

        
    }
};