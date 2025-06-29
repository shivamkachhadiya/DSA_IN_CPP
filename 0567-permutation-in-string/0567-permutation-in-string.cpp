class Solution {
public:
    bool issame(int freq1[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            freq[index]++;
        }
        int windowsize=s1.length();
        for(int i=0;i<s2.length();i++){
            int windowindex=0;
            int indx=i;
            int windowfreq[26]={0};
            while(windowindex < windowsize && indx<s2.length()){
                windowfreq[s2[indx]-'a']++;
                windowindex++;
                indx++;               

            }
            if(issame(freq,windowfreq)){
                return true;
            }
        }
        return false;
        
    }
};