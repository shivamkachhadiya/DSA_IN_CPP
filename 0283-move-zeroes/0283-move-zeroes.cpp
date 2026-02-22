class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto x: nums){
            if(x==0){
                freq[x]++;
            }
        }
        auto count=freq[0];
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)continue;
            ans.push_back(nums[i]);
        }
        while(count){
            ans.push_back(0);
            count--;
        }
        nums=ans;
    }
};