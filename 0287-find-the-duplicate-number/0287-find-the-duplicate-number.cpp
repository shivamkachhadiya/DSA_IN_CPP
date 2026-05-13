class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // unordered_map<int,int>freq;
        // for(int i=0;i<nums.size();i++){
        //     freq[nums[i]]++;
        //     if(freq[nums[i]]>1){
        //         return nums[i];
        //     }
        // }
        // return -1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            int j=i+1;
            if(nums[i]==nums[j]){
                return nums[i];
            }
        }
        return -1;
    }
};