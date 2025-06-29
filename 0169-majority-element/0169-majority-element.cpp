class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int>tmp;
        // int n=nums.size();
        // int major=n/2;
        // for(int i=0;i<n;i++){
        //     tmp[nums[i]]++;
        //     if(tmp[nums[i]]>major){
        //         return nums[i];
        //     }
        // }
        //  return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort the numsay

        int count = 1; // Count of current element
        int majorityCount = n / 2;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }
            if (count > majorityCount) {
                return nums[i];
            }
        }
        if (n == 1)
            return nums[0];

        return -1;
    }
};