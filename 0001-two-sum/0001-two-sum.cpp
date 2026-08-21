class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[arr[i]]=i;
        }
        for(int i=0;i<n;i++){
            int new_target=target-arr[i];
            if(map.find(new_target)!=map.end()&&map[new_target]!=i){
                return {{i,map[new_target]}};
            }
        }
        return {};
    }
};