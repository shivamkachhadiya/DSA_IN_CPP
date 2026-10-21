class Solution {
public:
    bool isPali(string &str){
        int start=0;
        int end=str.size()-1;

        while(start<end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void getAllPart(string s,vector<string>&part,vector<vector<string>>&ans){
        
        if(s.size()==0){
            ans.push_back(part);
            return;
        }

        for(int i=0;i<s.size();i++){
            string Currpart=s.substr(0,i+1);
            if(isPali(Currpart)){
                part.push_back(Currpart);
                getAllPart(s.substr(i+1),part,ans);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>part;
        vector<vector<string>>ans;
        getAllPart(s,part,ans);
        return ans;
    }
};