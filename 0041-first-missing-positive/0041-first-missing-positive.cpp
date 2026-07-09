class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n=nums.size();
       unordered_map<int,int>map;
       for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
       }
    
       for(int i=1;i<n+2;i++){
        if(map.find(i)==map.end()){
            return i;
        }
       }
       return -1;
    }
};