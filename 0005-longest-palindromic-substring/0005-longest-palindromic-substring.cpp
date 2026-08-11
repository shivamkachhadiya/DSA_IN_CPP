class Solution {
public:
    bool check(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    string result="";

    string longestPalindrome(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)){
                    if(j-i+1>result.size()){
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return result;
    }
    
};