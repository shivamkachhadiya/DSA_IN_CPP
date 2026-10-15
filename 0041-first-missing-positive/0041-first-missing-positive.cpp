class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }

        for(int i=1;i<n+2;i++){
            if(map.find(i)==map.end()){
                return i;
            }
        }
        return -1;
    }
};