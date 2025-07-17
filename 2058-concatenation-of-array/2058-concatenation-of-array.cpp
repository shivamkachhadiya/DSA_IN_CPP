class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            arr.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            arr.push_back(nums[i]);
        }
        return arr;
    }
};