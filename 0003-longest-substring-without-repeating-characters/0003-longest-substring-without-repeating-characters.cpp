class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n=s.size();
         int left=0;
         unordered_map<char,int>maap;
         int right=0;
         int maxlen=0;
         while(right<n){
            if(maap.find(s[right])==maap.end()|| maap[s[right]] < left){
                maxlen=max(maxlen,right-left+1);
                maap[s[right]]=right;
                right++;
            }else{
                left=maap[s[right]]+1;
                maap[s[right]]=right;
                maxlen=max(maxlen,right-left+1);
                right++;
            }
         }
         return maxlen;
    }
};