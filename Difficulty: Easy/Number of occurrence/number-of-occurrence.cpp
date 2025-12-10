class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        map<int,int>freq;
        for(auto i:arr){
            freq[i]++;
        }
        return freq[target];
    }
};
