class Solution {
public:
    int count=0;
    bool isValid(string &str){
        int start=0;
        int end=str.size()-1;
        while(start<end){
            if(str[start]!=str[end])return false;
            start++;
            end--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp.push_back(s[j]);
                if(isValid(temp)){
                    count++;
                }
            }
        }
        return count;
    }
};