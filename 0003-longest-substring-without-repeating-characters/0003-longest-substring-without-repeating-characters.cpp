class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>map;

        int n=s.size();
        int ans=0;
        int l=0,r=0;
        while(r<n){
            char curr=s[r];
            if(map.find(curr)!=map.end()){
                if (map[curr] >= l)
                    l=map[curr]+1;
                map[curr]=r;
            }else{
                map[curr]=r;
            }
            ans=max(ans,r-l+1);

            r++;
        }
        return ans;
    }
};