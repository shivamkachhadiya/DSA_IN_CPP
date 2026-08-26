class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int left=0;
        int mini=0;
        int right=0;
        vector<int>lastSeen={-1,-1,-1};
        while(right<n){
            lastSeen[s[right]-'a']=right;
            if(lastSeen[0]!=-1&&lastSeen[1]!=-1&&lastSeen[2]!=-1){
                mini=mini+(1+min({lastSeen[0],lastSeen[1],lastSeen[2]}));
            }
            right++;
        }
        return mini;
    }
};