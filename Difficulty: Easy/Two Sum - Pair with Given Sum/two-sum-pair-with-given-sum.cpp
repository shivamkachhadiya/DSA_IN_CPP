class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        map<int,int>mp;
        
        for(int i=0;i<arr.size();i++){
            int need=target-arr[i];
            if(mp.find(need)!=mp.end()){
                return true;
            }
            mp[arr[i]]=i;
        }
        return false;
    }
};