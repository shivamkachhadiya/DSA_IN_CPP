class Solution {
public:
    bool isSolve(string &s){
        int start=0;
        int end=s.size()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        if(s.size()==0)return true;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                temp+=(tolower(s[i]));
            }else{
                continue;
            }
        }
        return isSolve(temp);
    }
};