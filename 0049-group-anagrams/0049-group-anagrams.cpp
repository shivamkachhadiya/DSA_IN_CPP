class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        for(auto &x:strs){
            string temp=x;
            sort(x.begin(),x.end());
            map[x].push_back(temp);
        }
        vector<vector<string>>ans;
        for(auto &p:map){
            ans.push_back(p.second);
        }
        return ans;
    }
};