class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=1;i<=n;i++){
            total+=i;
        }

        int actualsum=0;
        for(auto i:nums){
            actualsum+=i;
        }


        return total-actualsum;
    }
};