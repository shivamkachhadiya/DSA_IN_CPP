class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int j=1;
        int k=target;
        int i=0;
        int n=nums.size();
        vector<int>tmp;
        for(int i=0;i<n;i++){
            int j=i+1;
            for(j;j<n;j++){
                if(nums[i]+nums[j]==k){
                    tmp.push_back(i);
                    tmp.push_back(j);

                }
            }
        }
        return tmp;
    
    }
};