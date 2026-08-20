class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+2,0);
        for(auto &b:bookings){
            int start=b[0];
            int end=b[1];
            int count=b[2];

            diff[start]+=count;
            diff[end+1]-=count;
        }
        vector<int>result;
        int CummulativeSum=0;
        for(int i=1;i<=n;i++){
            CummulativeSum+=diff[i];
            result.push_back(CummulativeSum);
        }
        return result;
    }
};