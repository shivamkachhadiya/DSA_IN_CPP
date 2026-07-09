class Solution {
public:
// eat
// tea
// ate

// Ye teeno same letters se bane hain.

// Agar in sabko sort kar do:

// eat -> aet
// tea -> aet
// ate -> aet

// Sabka sorted version same ho gaya.

// Hum isi sorted string ko key bana dete hain.

// Key       Original Words
// aet  ---> eat, tea, ate
// ant  ---> tan, nat
// abt  ---> bat
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        for(auto i:strs){
            string temp=i;
            sort(temp.begin(),temp.end());
            map[temp].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto&s:map){
            ans.push_back(s.second);
        }
        return ans;
    }
};