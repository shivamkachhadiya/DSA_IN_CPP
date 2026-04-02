class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int curr=1;
        int longest=1;
        if(arr.empty())return 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]){
               continue;
            }
            if(arr[i]==arr[i-1]+1){
                curr++;
            }else{
                longest=max(longest,curr);
                curr=1;
            }
        }
        return max(longest,curr);
    }
};