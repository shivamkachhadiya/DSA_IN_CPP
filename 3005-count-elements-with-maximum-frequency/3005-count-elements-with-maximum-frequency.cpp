class Solution {
public:
    int maxFrequencyElements(vector<int>& arr) {
        map<int, int> freq;
        int maxi = -1;
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
            maxi = max(maxi, freq[arr[i]]);

           
        }
        int count=0;
        for(auto i:freq){
            if(maxi==i.second){
                count++;
            }
        }
        if(maxi==1){
            return arr.size();
        }
        return count*maxi;
    }
};