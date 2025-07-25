class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //12
        //123
        int count=0;
        int s1=0;
        int s2=0;
        int n1=g.size();
        int n2=s.size();
        while(s1<n1&&s2<n2){
            if(s[s2] >= g[s1]){
                count++;
                s1++;
                                
            }
            s2++;
        }
        return count;
    }
};