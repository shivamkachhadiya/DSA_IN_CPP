class Solution {
public:
    int numberOfSubstrings(string s) {


        int left=0,right=0,count=0;
        unordered_map<char,int>freq;
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
            while(freq['a']>0&&freq['b']>0&&freq['c']>0){
                count += (n - i);
                freq[s[left]]--;
                left++;
            }
        }
        return count;
        
    }
};