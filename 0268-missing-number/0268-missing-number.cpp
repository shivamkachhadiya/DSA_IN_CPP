class Solution {
public:
    int missingNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        //013
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=i){
                return i;
            }
        }
        return arr.size();
    }
};