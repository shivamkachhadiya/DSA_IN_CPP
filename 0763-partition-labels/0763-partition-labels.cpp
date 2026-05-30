class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);
        // har char ka last index store karo
        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        
        vector<int> res;
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']); // current partition ka end update
            if(i == end) { 
                // partition complete ho gaya
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
