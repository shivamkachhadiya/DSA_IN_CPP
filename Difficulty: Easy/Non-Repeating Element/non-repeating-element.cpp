
class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // Complete the function
        unordered_map<int,int>map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(map[arr[i]]==1){
                return arr[i];
            }
        }
        return 0;
    }
};
