class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        unordered_map<string,vector<string>>map;
        for(auto &str:arr){
            string temp=str;
            sort(temp.begin(),temp.end());
            if(map.find(temp)==map.end()){
                map[temp].push_back(str);
            }else{
                map[temp].push_back(str);
            }
        }
        vector<vector<string>>ans;
        for(auto &x:map){
            ans.push_back(x.second);
        }
        return ans;
    }
};