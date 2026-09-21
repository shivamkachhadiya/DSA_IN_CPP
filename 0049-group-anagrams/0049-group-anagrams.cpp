class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>map;
        for(auto &s:strs){
            string temp=s;
            sort(temp.begin(),temp.end());
            map[temp].push_back(s);
        }
        for(auto &x:map){
            vector<string>temp_ans=x.second;
            ans.push_back(temp_ans);
        }
        return ans;
    }
};