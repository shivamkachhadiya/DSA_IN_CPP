class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diff(1005,0);
        for(auto &t:trips){
            int start=t[1];
            int end=t[2];
            int count=t[0];
            diff[start]+=count;
            diff[end]-=count;
        }
        vector<int>result;
        int cummulativeSum=0;
        for(int i=0;i<=1000;i++){
            cummulativeSum+=diff[i];
            if(cummulativeSum>capacity)return false;
        }
        return true;
    }
};